/*
 * debug.h
 * 
 * Debug print support
 * 
 * Copyright: Björn Skoglund
 */

#include "brainfuck.h"

#define ENABLE_DEBUG 1

#ifdef ENABLE_DEBUG
#define DEBUG(x) printf(x)
#else
#define DEBUG(x)
#endif

void print_op(op_t op);
void print(op_t* program, int size);

char* get_name(op_t op);
