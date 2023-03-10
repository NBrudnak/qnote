//despite cross include issues main shall list all .h files 
#include "cli.h"
#include "note.h"
#include "lex.h"
void main(int argc, char** argv){

	if (argc==1){
		printf("Note needs and argument\n");
		return;
	}
	//create and initialize lexer
	Lexer* lexer = createLexer();
	//proccess clargs
	Arg arg;
	arg = initArg(argc, argv, arg);
	handleArg(arg, lexer);
	lexerloop(lexer);

}


