/**********************************************
 * parse.c
 * 
 * Copyright Björn Skoglund
 *
 **********************************************/

#include "brainfuck.h"
#include "parser.h"

#include <stdio.h>

static op_t* program = NULL;
static int max_size = -1; 
static int pos = 0;

void init_parser(op_t* _program, int _max_size) {
  program = _program;
  max_size = _max_size;
  pos = 0;
}

static op_t get_op(char c) {
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

void parse_char(char c) {
  if (pos >= max_size ) {
    printf("error: Program too big for memory."); 
    exit(-1);
  }

  op_t op;
  if ((op = get_op(c)) != NOP) {
    program[pos++] = op;
  }
}

int check_program() {
  return pos;
}

void drop_errors(error_t* errors) {
  // Empty.
}


