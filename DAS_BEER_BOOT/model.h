#ifndef __MODEL_H__
#define __MODEL_H__

#include "object.h"
#include <list>
#include <map>

class Model{
public:
	std::vector<Object *> objects;
	std::map<char*, Meterial*> meterial_map;
	std::vector<Vertex *>			vv_list;
	std::vector<Vertex_normal *>	vn_list;
	std::vector<Vertex_texture *>	vt_list;
	std::vector<Vertex_param *>		vp_list;

	vector3f center;

	Model(){
		objects.clear();
		meterial_map.clear();

		vv_list.clear();
		vt_list.clear();
		vn_list.clear();
		vp_list.clear();

		center.set(0,0,0);
	}
	void setcenter(vector3f nc)
	{
		center.copy(nc);
	}
};
#endif