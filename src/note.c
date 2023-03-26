#include "note.h"



Note* noteCreateNote(Token* tok){

	Note* newNote = malloc((sizeof(Note)));
	newNote-> ID = tok->value;
	newNote-> parent = NULL;
	newNote->child = NULL;
	return newNote;
}	

void noteInsertNote(Note* parent, Note* child){

	parent->child = child;
}

Root* noteParseTokens(Token* tokArr[]){

	Root* root = malloc(sizeof(Root));
	root->headerChild = NULL;
	root->metadata = "test file";
	root->noteCount = 0;

	while (root->noteCount<=(sizeof(&tokArr)/sizeof(tokArr[0]))){

		
	}

	return root;
}









			
