#include "lex.h"

//allocate memory for lexer
Lexer* createLexer(){

	Lexer* lexer = malloc(sizeof(Lexer));
	lexer->cur = 0;
	lexer->tbcur = 0;
	lexer->buffer = " ";
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
	printf("token create with type: %d and value: %s\n",type, value);
	return tok;
}
		
void lexerloop(Lexer* lexer){

	while(lexer->cur<strlen(lexer->buffer)){

		lexer->tempBuffer[lexer->tbcur]=lexer->buffer[lexer->cur];
		lexerLex(lexer);
	}
}

void lexerHandleID(Lexer* lexer){

	lexer->tempBuffer[strlen(lexer->tempBuffer)-1] = '\0';
	lexer->tokArr[lexer->curTok] =
		lexerCreateToken(ID,lexer->tempBuffer);
	lexer->curTok++;
}
void lexerLex(Lexer* lexer){



	switch(lexer->buffer[lexer->cur]){

		case '>':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleID(lexer);
			}
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(GR," ");

			
		        lexer->cur++;
			lexer->curTok++;
			memset(lexer->tempBuffer,0,strlen(lexer->tempBuffer));
			lexer->tbcur = 0;


			
			break;

		case '*':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleID(lexer);
			}
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(SD," ");

		        lexer->cur++;
			lexer->curTok++;
			memset(lexer->tempBuffer,0,strlen(lexer->tempBuffer));

			break;

		case ';':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleID(lexer);
			}
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(SEMI," ");
		        lexer->cur++;
			lexer->curTok++;
			memset(lexer->tempBuffer,0,strlen(lexer->tempBuffer));

			break;

		case ':':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleID(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(COLON," ");

		        lexer->cur++;
			lexer->curTok++;
			memset(lexer->tempBuffer,0,strlen(lexer->tempBuffer));
			break;
		
		case '{':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleID(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(LBRACKET," ");

		        lexer->cur++;
			lexer->curTok++;
			memset(lexer->tempBuffer,0,strlen(lexer->tempBuffer));
			break;

		case '}':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleID(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(RBRACKET," ");

		        lexer->cur++;
			lexer->curTok++;
			memset(lexer->tempBuffer,0,strlen(lexer->tempBuffer));
			break;

		case '[':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleID(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(LBRACE," ");
		        lexer->cur++;
			lexer->curTok++;
			memset(lexer->tempBuffer,0,strlen(lexer->tempBuffer));
			break;

		case ']':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleID(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(RBRACE," ");

		        lexer->cur++;
			lexer->curTok++;
			memset(lexer->tempBuffer,0,strlen(lexer->tempBuffer));
			break;

		default:
			lexer->cur++;
			lexer->tbcur++;
			break;
}
}























