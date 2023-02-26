#ifndef NOTE_H
#define NOTE_H
#include <stdlib.h>

typedef struct NOTE{

	char* content;
	struct NOTE* parent;
	struct NOTE* left;
	struct NOTE* right;
}Note;

Note* createNote(char* content);

Note* insertNote(Note* parent, char* content, int lor);
void articiallyPopulateTree(Note* root);

#endif
