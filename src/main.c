//despite cross include issues main shall list all .h files 
#include "user.h"
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
	lexer = readFileToString(lexer,"notes.nl");

	//create note tree
	Note* root = createNote("root");
	fakePopulateTree(root);

	//proccess clargs
	Arg arg;
	arg = initArg(argc, argv, arg);

	//create user and handle args
	User* mainUser = initUser(root);
	userHandleArg(mainUser, arg);

	lexerloop(lexer);
	printf("%d\n",lexer->curTok);
	for (int i = 0;i<lexer->curTok;i++){

		printf("%d %d\n",lexer->tokArr[i]->type, i);
	}

}


