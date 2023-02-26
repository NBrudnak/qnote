#ifndef CLI_H
#define CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "note.h"
//101 is number used for when command has an error
#define ERROR 1001



typedef struct Arg{

	char buffer[300];
	int argc;
	int los;
	int command;
}Arg; 

Arg initArg(int argc, char** argv, Arg arg);
void viewNotes();
void handleArg(Arg arg);


#endif
