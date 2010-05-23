/*
 * executor.h
 * 
 * Executes brainfuck programs
 * 
 * Copyright: Bj�rn Skoglund
 */

#pragma once
#include "brainfuck.h"

void execute(op_t* program, int size);
