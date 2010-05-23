/*
 * executor.h
 * 
 * Executes brainfuck programs
 * 
 * Copyright: Björn Skoglund
 */

#pragma once
#include "brainfuck.h"

void execute(op_t* program, int size);
