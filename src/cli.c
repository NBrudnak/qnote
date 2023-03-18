#include "cli.h"
//struct for arguments

/*
 * n: think about making an enum with commands if it gets
 * too complicated 
*/
char* comListL[]= {
	"list",
	"help",
	"file",
	"note"
};

//list of short commands
char* comListS[]= {
	"-l",
	"-h",
	"-f"
	"-n"
};


Arg initArg(int argc, char** argv, Arg arg){


	//dump args into struct	
	strcpy(arg.buffer,argv[1]);
	arg.argc = argc;
	arg.los = 0;
	arg.command = 1001;

	if (arg.buffer[0] == '-'){
		arg.los = 1;
	}
	
	
	//check if command is in list
	if (arg.los == 0){
		for (size_t i = 0; 
		i<sizeof(comListL)/sizeof(comListL[0]);
		i++){
//			printf("%s: %s\n", arg.buffer, comListL[i]);
			if (strcmp(argv[1],comListL[i])==0){
				arg.command = i;
//				printf("%d\n",arg.command);
			}
		}
	}
	else{
		for (size_t i = 0; 
		i<sizeof(comListS)/sizeof(comListS[0]);
		i++){
		//	printf("%s: %s\n", arg.buffer, comListS[i]);
			if (strcmp(argv[1],comListS[i])==0){
				arg.command = i;
			}
		}
	}
	
	if (arg.command == 3){
		
		memcpy(arg.buffer,argv[2],strlen(argv[2]));
		return arg;
	}
	if (argc>2){

		char nextWord[20];
		for (int c = 2;c<argc; c++){

			if ((c+1)<=argc){
				char space[] = " ";
				strcat(arg.buffer,space);
			}
			strcpy(nextWord,argv[c]);
			strcat(arg.buffer,nextWord);
		}
	}


	if (arg.command != 1001){
		return arg;
	}

	//if command did not pass check it gets passed as an error	
	printf("%s: is an invlid command\n", arg.buffer);
	return arg;

}

void handleArg(Arg arg, Lexer* lexer){

	switch(arg.command){

		case 0:
			printf("listing notes\n");
			break;
		case 1:
			printf("Helping user\n");
			break;
		case 2:
			printf("file command\n");
			break;
		case 3:
			lexer->buffer = malloc(sizeof(arg.buffer));
			strcpy(lexer->buffer, arg.buffer);
			break;
	}
}
			
	










