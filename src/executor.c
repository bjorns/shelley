/*
 * executor.c
 * 
 * Executes brainfuck programs
 * 
 * Copyright: Björn Skoglund
 */

#include "brainfuck.h"
#include "debug.h"

#include <stdio.h>

int pc;
int ptr;

#define STACK_SIZE 256
int stack[STACK_SIZE];
int stack_ptr;

long* _buffer;
op_t* _program;

static void push(int pc) {
  if (stack_ptr >= STACK_SIZE) {
    printf("error: stack overflow at char %d\n", pc);
  }
  stack[stack_ptr++] = pc;
}

static int pop() {
  return stack[--stack_ptr];
}

  
static int execute_op(int pc) {
  if (debug) 
    fprintf(stderr, "executing %s at %d\n", get_name(_program[pc]), pc);
  switch(_program[pc]) {
  case NEXT:
    ptr++;
    break;
  case PREV:
    ptr--;
    break;
  case INC:
    _buffer[ptr]++;
    break;
  case DEC:
    _buffer[ptr]--;
    break;
  case BEGIN:
    push(pc);
    break;
  case LOOP:
    if (_buffer[ptr] != 0) {
      return pop();
    }
    break;
  case WRITE:
    printf("%c", (char)_buffer[ptr]);
    break;
  case READ:
    _buffer[ptr] = (long)getchar();
    break;
  default:
    fprintf(stderr, "Unknown operation %d at position %d\n", _program[pc], pc);
    exit(2);
  }
  return ++pc;
}

void execute(long* buffer, op_t* program, int size) {
  _buffer = buffer;
  _program = program;
  pc = 0;
  ptr = 0;
  stack_ptr = 0;

  if (debug) 
    fprintf(stderr,"Executing program of size %d\n", size);
  while(pc < size) {
    pc = execute_op(pc);
  }
}
