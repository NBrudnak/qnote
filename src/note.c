#include "note.h"


Root* noteCreateRoot(Token* tokArr[], int numTokens){

	Root* root = malloc(sizeof(root));
	root->headerChild = NULL;
	root->metadata = "test metatdata";
	memcpy(root->tokArr, tokArr, sizeof(root->tokArr));
	root->numTokens = numTokens;
	root->curTok = 0;
	return root;
}	

Note* noteCreateNote(Token* tokArr[]){

	Note* newNote = malloc((sizeof(Note)));
	newNote-> parent = NULL;
	newNote->child = NULL;
	return newNote;
}	


void noteInsertNote(Note* parent, Note* child){

	parent->child = child;
}

//Note* noteDefineNote(Root* root){
	


Root* noteParseTokens(Root* root){

	printf("number of Tokens to proccess: %d\n",root->numTokens);

	while (root->tokArr[root->curTok]->ID!=__ENDPROGRAM__){

		if ( root->tokArr[root->curTok]->ID==GR){

			printf("note created\n");
		}
		
		printf("nothing made\n");
		root->curTok++;
	}

	return root;
}









			
