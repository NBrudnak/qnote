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
	char* metadata;
	Token* tokArr[200];
	int numTokens;
	int curTok;
}Root;

typedef struct OPERATOR{
	
	int type;
	
}Operator;

Root* noteCreateRoot(Token* tokArr[], int numTokens);
Note* noteCreateNote(Token* tokArr[]);
void NoteInsertNote(Note* parent, Note* child);
Root* noteParseTokens(Root* root);
#endif
