#include "note.h"



Note* noteCreateNote(Token* tokArr[]){

	Note* newNote = malloc((sizeof(Note)));
	newNote-> parent = NULL;
	newNote->child = NULL;
	return newNote;
}	

void noteInsertNote(Note* parent, Note* child){

	parent->child = child;
}

Root* noteParseTokens(Token* tokArr[], int numTokens){

	Root* root = malloc(sizeof(Root));
	root->headerChild = NULL;
	root->metadata = "test file";
	root->noteCount = 0;
	
	int i=0;
	while (root->noteCount<numTokens){

		if ( tokArr[i]->ID=GR){

			Note* curNote = noteCreateNote(tokArr);
			printf("note created\n");
			root->noteCount++;
		}
	}

	return root;
}









			
