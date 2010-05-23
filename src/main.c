/*
 * main.c
 * 
 * Copyright: Björn Skoglund
 */

#include "brainfuck.h"
#include "parser.h"

#include <stdlib.h>
#include <stdio.h>

#include "debug.h"

static long* buffer;
static op_t* program;

void init() {
  buffer = (long*)malloc(BUFFER_SIZE*sizeof(long));
  program = (op_t*)malloc(MAX_PROGRAM_SIZE*sizeof(op_t));
  init_parser(program, MAX_PROGRAM_SIZE);
}

void finish() {
  free(buffer);
  free(program);
}

int main() {
  init();

  char c;
  while((c = getchar()) != EOF) {
    parse_char(c);
  }
  int size = check_program();

  print(program,size);

  finish();
  return 0;
}
