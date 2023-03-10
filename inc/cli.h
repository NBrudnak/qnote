#ifndef CLI_H
#define CLI_H

#include <note.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lex.h"

typedef struct Arg{

	char buffer[1000];
	int argc;
	int los;
	int command;
}Arg; 

Arg initArg(int argc, char** argv, Arg arg);
void handleArg(Arg arg, Lexer* lexer);

#endif
