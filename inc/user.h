#ifndef USER_H
#define USER_H
#include <cli.h>
#include <note.h>

typedef struct USER{

	Note* rootNote;

}User;

User* initUser(Note* rootNote);
#endif
