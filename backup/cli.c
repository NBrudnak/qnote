#include "cli.h"
//struct for arguments

/*
 * n: think about making an enum with commands if it gets
 * too complicated 
*/
char* comListL[]= {
	"list",
	"help"
};

//list of short commands
char* comListS[]= {
	"-l",
	"-h",
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
	
	//if multiple clargs. concatonate into one
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
	
	//check if command is in list
	if (arg.los == 0){
		for (size_t i = 0; 
		i<sizeof(comListL)/sizeof(comListL[0]);
		i++){
		//	printf("%s: %s\n", arg.buffer, comListL[i]);
			if (strcmp(arg.buffer,comListL[i])==0){
				arg.command = i;
				break;
			}
		}
	}
	else{
		for (size_t i = 0; 
		i<sizeof(comListS)/sizeof(comListS[0]);
		i++){
		//	printf("%s: %s\n", arg.buffer, comListS[i]);
			if (strcmp(arg.buffer,comListS[i])==0){
				arg.command = i;
				break;
			}
		}
	}
	if (arg.command != 1001){
		return arg;
	}

	//if command did not pass check it gets passed as an error	
	printf("%s: is an invlid command\n", arg.buffer);
	return arg;

}
void listNotes(){

	Note* rootNote = createNote("ROOT");
}
//main switch for commands to pass through
void handleArg(Arg arg){

	switch (arg.command){

		case 0:
			printf("list notes!!!!\n");
			listNotes();
			break;
		case 1:
			printf("helping You!!!\n");
			break;
		case 1001:
			printf("error logged\n");
	}
}



