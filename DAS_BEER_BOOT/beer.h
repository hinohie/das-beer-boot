#ifndef __BEER_H__
#define __BEER_H__

#include <vector>
#include "meterial.h"	// for color 
#include "model.h"

class Beer{
public:
	float deep_dark_rate;
	std::vector<Color> color_list;

	Beer(Model *model, float deep_dark)
	{
		color_list.clear();
		deep_dark_rate = deep_dark;

		for(int i=0; i<model->objects.size(); i++)
		{
			Object *obj = model->objects[i];
			for(std::list<Flag>::iterator it = obj->flags.begin(); it != obj->flags.end(); it++)
			{
				Color cc;
				cc.setf(0.0, 0.0, 0.0, 0.0);
				color_list.push_back(cc);
			}
		}
	}
	void setcolor(int it, Color color)
	{
		color_list[it].copy(color);
	}
};

#endif