/*
 * brainfuck.c
 * 
 * Copyright: Björn Skoglund
 */

#include <stdlib.h>
#include <stdio.h>

typedef enum {
  NOP,
  NEXT, PREV,
  INC, DEC,
  BEGIN,LOOP,
  WRITE, READ,
} op_t;

#define BUFFER_SIZE 0x8000
#define PROGRAM_SIZE 0x8000

static long* buffer;
static op_t* program;

void init() {
  buffer = (long*)malloc(BUFFER_SIZE*sizeof(long));
  program = (op_t*)malloc(PROGRAM_SIZE*sizeof(op_t));
}

void finish() {
  free(buffer);
  free(program);
}

op_t parse(char c) {
  switch(c) {
  case '>': return NEXT;
  case '<': return PREV;
  case '+': return INC;
  case '-': return DEC;
  case '[': return BEGIN;
  case ']': return LOOP;
  case '.': return WRITE;
  case ',': return READ;
  default: 
    return NOP;
  }
}

#define CASE(x) case x: printf(#x "\n"); break
void print_op(op_t op) {
  switch (op) {
    CASE(NEXT);
    CASE(PREV);
    CASE(INC);
    CASE(DEC);
    CASE(BEGIN);
    CASE(LOOP);
    CASE(WRITE);
    CASE(READ);
  default:
    break;
  }
}

void print(op_t* program, int size) {
  for (int i=0; i < size; ++i) {
    print_op(program[i]);
  }
}

int main() {
  init();
  char c;
  op_t op;
  int i = 0;
  while((c = getchar()) != EOF) {
    if ((op = parse(c)) != NOP) {
      program[i++] = op;
    }
  }
  print(program,i);

  finish();
  return 0;
}
