#include "cli.h"

void main(int argc, char** argv){

	Arg arg;
	initArg(argc, argv, arg);
	handleArg(arg);

}


