#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "meterial.h"
#include "flag.h"
#include "vertex.h"

#include <list>

class Object{
public:
	Object(){
		name = "";
		mtl = NULL;

		flags.clear();
		smooth = false;
	}
	char* name;
	Meterial *mtl;
	std::list<Flag> flags;
	bool smooth;
};

#endif