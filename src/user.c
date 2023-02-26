#include "user.h"


User* initUser(Note* rootNote){
	User* mainUser = malloc(sizeof(User));
	mainUser->rootNote = rootNote;
	return mainUser;
}

void userHandleArg(User* user, Arg arg){
	
	switch (arg.command){
		case 0:
			printf("list notes!!!!\n");
			listNotes(user->rootNote);
			break;
		case 1:
			printf("helping You!!!\n");
			break;
		case 2:
			char * buffer;
			printf("note name: ");
			scanf("%s", &buffer);
			createNote(buffer);
			break;
		case 1001:
			printf("error logged\n");
	}
}


