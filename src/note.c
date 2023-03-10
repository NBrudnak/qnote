#include "note.h"



Note* createNote(Token* tok){

	Note* newNote = malloc((sizeof(Note)));
	newNote-> ID = tok->value;
	newNote-> parent = NULL;
	newNote->child = NULL;
	return newNote;
}	

void insertNote(Note* parent, Note* child){

	parent->child = child;
}


