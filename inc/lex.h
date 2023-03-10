#ifndef LEX_H
#define LEX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
enum Types{
	GR,//>
	SEMI,//;
	COLON,//:
	SD,//*
	ID,//note id
	CONT,//note contents
	LBRACKET,//{
	RBRACKET,//}
	LBRACE,//[
	RBRACE,//]
};

typedef struct Token{

	int type;
	char* value;

}Token;


typedef struct Lexer{

	int cur, curTok, tbcur;
	char *buffer;
	char tempBuffer[50];
	FILE* fp;
	Token* tokArr[200];

}Lexer;

Lexer* createLexer();
Lexer* readFileToString(Lexer* lex, char* fileName);
Token* lexerCreateToken(int type,char* value);
void lexerLex(Lexer* lexer);
void lexerloop(Lexer*lexer);
void lexerHandleID(Lexer* lexer);
#endif 
