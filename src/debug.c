/*
 * debug.c
 * 
 * Copyright: Björn Skoglund
 */

#include "brainfuck.h"
#include <stdio.h>

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
    printf("warning: unknown operation %x\n", op);
    break;
  }
}

void print(op_t* program, int size) {
  for (int i=0; i < size; ++i) {
    print_op(program[i]);
  }
}
