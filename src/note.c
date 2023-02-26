#include "note.h"



Note* createNote(char* content){

	Note* newNote = malloc((sizeof(Note)));
	newNote-> content = content;
	newNote-> parent = NULL;
	newNote->left = NULL;
	newNote->right = NULL;
	return newNote;
}	

Note* insertNote(Note* parent, char* content, int lor){

	Note* nodeNote = createNote(content);
	if (lor){
		nodeNote->parent = parent;
		parent->right = nodeNote;
		return nodeNote; 
	}
	nodeNote->parent = parent;
	parent->left = nodeNote;
	return nodeNote;

}

void fakePopulateTree(Note* root){

	Note* newNote  = createNote("TL");
	Note* newNote2 = createNote("TLR");
	Note* newNote3 = createNote("TLL");
	Note* newNote4 = createNote("TLLR");
	Note* newNote5 = createNote("TLLRL");

	root->left = newNote;
	newNote->right = newNote2;
	newNote->left = newNote3;
	newNote3->right = newNote4;
	newNote4->left = newNote5;


}

void listNotes(Note* note){

	Note* curNote = note;

	while(curNote->left!=NULL){

		printf("%s\n",curNote->left->content);
		curNote = curNote->left;
	}
}









	


//void ListNotes(
