#include "beer.h"
#include "meterial.h"

#include "funccollect.h"

Beer *butter_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc((float)0.9, 0.88, 0.4);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}

Beer *beer_init(Model *model, float deep_dark,int fill_rate)
{
	Beer *butter = new Beer(model, deep_dark);

	int dd[5] = {29, 39, 39, 59};

	for(int i=0; i<butter->color_list.size(); i++)
	{
		if(i > dd[fill_rate] && i < 50)continue;
		if(fill_rate < 2 && i >62) continue;
		if(fill_rate < 3 && i >83) continue;
		if(fill_rate == 2 && i >62 && i%2 == 0) continue;
		Color cc;
		cc.setd(252,186, 66);
		butter->setcolor(i,cc);
	}

	return butter;
}

Beer *beer_with_white_init(Model *model, float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	int dd[5] = {29, 39, 39, 59};

	for(int i=0; i<butter->color_list.size(); i++)
	{
		Color cc(1.0, 1.0, 0.97);
		butter->setcolor(i,cc);
		if(i > dd[2] && i < 50)continue;
		if(i >83) continue;
		if(i >62 && i%2 == 0) continue;
		cc.setd(252, 166, 66);
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *pink_init(Model *model, float deep_dark,int fill_rate)
{
	Beer *butter = new Beer(model, deep_dark);

	int dd[5] = {29, 39, 39, 59};

	for(int i=0; i<butter->color_list.size(); i++)
	{
		if(i > dd[fill_rate] && i < 50)continue;
		if(fill_rate < 2 && i >62) continue;
		if(fill_rate < 3 && i >83) continue;
		if(fill_rate == 2 && i >62 && i%2 == 0) continue;
		Color cc;
		cc.setd(234, 149, 164);
		butter->setcolor(i,cc);
	}
	return butter;
}

Beer *energy_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(234, 149, 164);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *chese_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	for(int i=0; i<butter->color_list.size(); i++)
	{
		Color cc(0.926, 0.639, 0.303);
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *pancake_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(202, 149, 10);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *sosigy_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(158, 120, 125);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *egg_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	for(int i=0; i<butter->color_list.size(); i++)
	{
		Color cc;
		cc.setd(255, 230, 116);
		if( i % 23 == 1 || i % 17 == 2 || i % 11 == 7)
			cc.setd(197, 143, 39);
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *bakern_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(130, 35, 44);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *sugar_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(198, 195, 206);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *geapi_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(113, 76, 51);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *sobrot_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(84, 54, 39);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *gulasi_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(110, 77, 48);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *burabt_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(145, 135, 143);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *spotch_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(175, 164, 143);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *hasen_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(149, 121, 85);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}
Beer *mayo_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	cc.setd(252, 252, 255);
	for(int i=0; i<butter->color_list.size(); i++)
	{
		butter->setcolor(i,cc);
	}

	return butter;
}

Beer *cake_init(Model *model,float deep_dark)
{
	Beer *butter = new Beer(model, deep_dark);

	Color cc;
	for(int i=0; i<butter->color_list.size(); i++)
	{
		if(rand()%3 == 0)
			cc.setd(252, 252, 255);
		else
			cc.setd(69, 52, 59);
		butter->setcolor(i,cc);
	}

	return butter;
}