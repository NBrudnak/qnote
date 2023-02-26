#include "lex.h"

//allocate memory for lexer
Lexer* createLexer(){

	Lexer* lexer = malloc(sizeof(Lexer));
	lexer->cur = 0;
	lexer->buffer = 0;
	return lexer;

}

Lexer* readFileToString(Lexer* lex, char* fileName){

	long length;
	
	lex->fp = fopen(fileName,"rb");
	if (lex->fp){

		fseek (lex->fp,0,SEEK_END);
		length = ftell (lex->fp);
		fseek (lex->fp, 0, SEEK_SET);
		lex->buffer = malloc (length);
		if (lex->buffer){
		       	fread(lex->buffer,1,length,lex->fp);
		//	printf("%s\n",lex->buffer);
		}
		fclose(lex->fp);
	}
	return lex;
}



Token* lexerCreateToken(int type, char* value){

	Token* tok= malloc(sizeof(Token));
	tok->type = type;
	tok->value = value;
	printf("token create with type: %d\n",type);
	return tok;
}
		
void lexerloop(Lexer* lexer){

//	printf("thing: %ld\n", (strlen(lexer->buffer)));

//	printf("%s\n", lexer->buffer);
	while(lexer->cur<strlen(lexer->buffer)){

		lexerLex(lexer);
//		printf("char: %c\n", lexer->buffer[lexer->cur]);

	}
}

void lexerLex(Lexer* lexer){

	switch(lexer->buffer[lexer->cur]){

		case 'd':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(D," ");
			lexer->cur++;
			lexer->curTok++;
			break;

		case '>':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(GR," ");

		        lexer->cur++;
			lexer->curTok++;
			
			break;

		case '*':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(SD," ");

			lexer->cur++;
			lexer->curTok++;
			break;
		case 'E':
			if(lexer->buffer[lexer->cur+1]='X'){
				lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(EX," ");

				lexer->cur+2;
				lexer->curTok++;

			}
			break;

		case ';':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(SEMI," ");

			lexer->cur++;
			lexer->curTok++;
			break;

		case ':':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(COLON," ");

			lexer->cur++;
			lexer->curTok++;
			break;
		
		case '{':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(LBRACKET," ");

			lexer->cur++;
			lexer->curTok++;
			break;

		case '}':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(RBRACKET," ");

			lexer->cur++;
			lexer->curTok++;
			break;

		case '[':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(LBRACE," ");

			lexer->cur++;
			lexer->curTok++;
			break;

		case ']':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(RBRACE," ");

			lexer->cur++;
			lexer->curTok++;
			break;

		default:
			lexer->cur++;
			break;
	}

}


	

























