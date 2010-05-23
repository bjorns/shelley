/*
 * debug.c
 * 
 * Copyright: Björn Skoglund
 */

#include "brainfuck.h"
#include <stdio.h>

#define NAME(x) case x: return #x;
char* get_name(op_t op) {
  switch (op) {
    NAME(NOP);
    NAME(NEXT);
    NAME(PREV);
    NAME(INC);
    NAME(DEC);
    NAME(BEGIN);
    NAME(LOOP);
    NAME(WRITE);
    NAME(READ);
  default:
    printf("warning: cannot get name for operation %x\n", op);
    return "UNKNOWN";
  }
}

#define CASE(x) case x: printf( "%d: %s\n", i, get_name(x)); break
void print_op(int i, op_t op) {
  switch (op) {
    CASE(NOP);
    CASE(NEXT);
    CASE(PREV);
    CASE(INC);
    CASE(DEC);
    CASE(BEGIN);
    CASE(LOOP);
    CASE(WRITE);
    CASE(READ);
  default:
    printf("warning: unknown operation %x\n", op);
    break;
  }
}

void print(op_t* program, int size) {
  printf("Program of size %d\n", size);
  for (int i = 0; i < size; ++i) {
    print_op(i, program[i]);
  }
}
