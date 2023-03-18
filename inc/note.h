#ifndef NOTE_H
#define NOTE_H
#include <stdlib.h>
#include <stdio.h>
#include "lex.h"
typedef struct NOTE{

	char* ID;
	struct NOTE* parent;
	struct NOTE* child;
}Note;
typedef struct OPERATORE{
	
	int type;
	
}Operator;


Note* createNote(Token* tok);
void insertNote(Note* parent, Note* child);

#endif
