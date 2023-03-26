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

typedef struct ROOT{

	Note* headerChild;
	int noteCount;
	char* metadata;
}Root;

typedef struct OPERATOR{
	
	int type;
	
}Operator;


Note* noteCreateNote(Token* tokArr[]);
void NoteInsertNote(Note* parent, Note* child);
Root* noteParseTokens(Token* toakArr[], int numTokens);
#endif
