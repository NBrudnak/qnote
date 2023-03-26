#include "lex.h"

//allocate memory for lexer
//lexer struct is manipulated via one master pointer
Lexer* createLexer(){

	Lexer* lexer = malloc(sizeof(Lexer));
	lexer->cur = 0;
	lexer->tbcur = 0;
	lexer->buffer = " ";
	return lexer;

}
//populates lexer buffer with input
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


//Universal token allocator
Token* lexerCreateToken(int ID, char* value){

	Token* tok= malloc(sizeof(Token));
	tok->ID = ID;
	tok->value = value;
	printf("token create with ID: %d and value: %s\n",ID, value);
	return tok;
}

//main lexer loop
//*consider refactoring only loops one thing but may provide funcitonality later
void lexerloop(Lexer* lexer){

	while(lexer->cur<strlen(lexer->buffer)){

		lexerLex(lexer);
		//printf("lexer buffer: %s\n", lexer->tempBuffer);
	}
	lexerCreateToken(__ENDPROGRAM__, ">:)");
}

// handles char data between operands
void lexerHandleString(Lexer* lexer){

	//sets null terminator at end of string
	lexer->tempBuffer[strlen(lexer->tempBuffer)] = '\0';
	//add sting as token to master token array
	lexer->tokArr[lexer->curTok] =
		lexerCreateToken(STRING,lexer->tempBuffer);
	//prep next token
	lexer->curTok++;
	//set tempbuffer index to 0
	lexer->tbcur= 0;
	printf("proccessing buffer {VAL}:\n %s\n",lexer->tempBuffer);
	//reset tempbuffer 
	memset(lexer->tempBuffer,0, sizeof(lexer->tempBuffer));
}

//main switch for operator identification
//also responsible for tempbuffer population
void lexerLex(Lexer* lexer){



	switch(lexer->buffer[lexer->cur]){

		case '>':
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(GR,">");

			lexer->curTok++;
			lexer->cur++;
			break;

		case '*':
			//if tempbuffer contains an ID proccess ID
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleString(lexer);
			}
			//create token for identified operator
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(SD,"*");
			
			//set indexs for token and lexer buffer
			lexer->curTok++;
			lexer->cur++;

			break;

		case ';':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleString(lexer);
			}
			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(SEMI,";");

			lexer->curTok++;
			lexer->cur++;

			break;

		case ':':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleString(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(COLON,":");

			lexer->curTok++;
			lexer->cur++;

			break;
		
		case '{':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleString(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(LBRACKET,"{");

			lexer->curTok++;
			lexer->cur++;
			break;

		case '}':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleString(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(RBRACKET,"}");

			lexer->curTok++;
			lexer->cur++;
			break;

		case '[':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleString(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(LBRACE,"[");

			lexer->curTok++;
			lexer->cur++;
			break;

		case ']':
			if(isalnum(lexer->tempBuffer[0])||lexer->tempBuffer[0] == ' '){
				lexerHandleString(lexer);
			}

			lexer->tokArr[lexer->curTok] = 
				lexerCreateToken(RBRACE,"]");

			lexer->curTok++;
			lexer->cur++;

			break;

		default:
			//if no operator is detected put char into tempbufer and update 
			//tempbuffer and lexerbuffer indexes 
			lexer->tempBuffer[lexer->tbcur]=lexer->buffer[lexer->cur];
			lexer->cur++;
			lexer->tbcur++;
			break;
	}


	
}























