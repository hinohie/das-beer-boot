#ifndef __FLAG_H__
#define __FLAG_H__

#include "vertex.h"
#include <vector>

class Flag{
public:
	std::vector<Vertex *>			vv;
	std::vector<Vertex_normal *>	vn;
	std::vector<Vertex_texture *>	vt;

	vector3f fnormal;

	Flag(){
		vv.clear();
		vn.clear();
		vt.clear();
	}
};

#endif