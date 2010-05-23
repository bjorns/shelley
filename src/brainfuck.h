/*
 * brainfuck.h
 * 
 * Language environment definitions
 * 
 * Copyright: Björn Skoglund
 */

#pragma once

// All known operations.
typedef enum {
  NOP,
  NEXT, PREV,
  INC, DEC,
  BEGIN,LOOP,
  WRITE, READ,
} op_t;

// Environment boundries
#define BUFFER_SIZE 0x8000
#define MAX_PROGRAM_SIZE 0x8000

