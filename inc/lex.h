#ifndef LEX_H
#define LEX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Types{
	D,//d
	SD,//*
	EX,//EX
	GR,//>
	SEMI,//;
	COLON,//:
	ID,
	value,
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

	int cur, curTok;
	char *buffer;
	FILE* fp;
	Token* tokArr[200];

}Lexer;

Lexer* createLexer();
Lexer* readFileToString(Lexer* lex, char* fileName);
Token* lexerCreateToken(int type,char* value);
void lexerLex(Lexer* lexer);
void lexerloop(Lexer*lexer);
#endif 
