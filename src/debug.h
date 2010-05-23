/*
 * debug.h
 * 
 * Debug print support
 * 
 * Copyright: Björn Skoglund
 */

#pragma once

#include "brainfuck.h"
#include <stdbool.h>

extern bool debug;

void print_op(op_t op);
void print(op_t* program, int size);

char* get_name(op_t op);
