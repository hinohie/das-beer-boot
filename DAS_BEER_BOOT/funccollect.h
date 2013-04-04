#ifndef __FUNCCOLLECT_H__
#define __FUNCCOLLECT_H__

#include <stdlib.h>
#include <glut.h>

#include "beer.h"
#include "model.h"

Model *getModel(const char* src);
void PRINT(Model* model);		//for debug

void draw_Vertex(Model *model);
void draw_Line(Model *model);
void draw_Flag(Model *model);
void draw(Model *model,GLenum type, Beer *beer);


Beer *butter_init(Model *model,float deep_dark);
Beer *beer_init(Model *model, float deep_dark, int fill_rate);
Beer *beer_with_white_init(Model *model, float deep_dark);
Beer *pink_init(Model *model, float deep_dark,int fill_rate);
Beer *energy_init(Model *model,float deep_dark);
Beer *chese_init(Model *model,float deep_dark);

Beer *pancake_init(Model *model,float deep_dark);
Beer *sosigy_init(Model *model,float deep_dark);
Beer *egg_init(Model *model,float deep_dark);
Beer *bakern_init(Model *model,float deep_dark);
Beer *geapi_init(Model *model,float deep_dark);
Beer *sugar_init(Model *model,float deep_dark);

Beer *sobrot_init(Model *model,float deep_dark);
Beer *gulasi_init(Model *model,float deep_dark);
Beer *burabt_init(Model *model,float deep_dark);
Beer *spotch_init(Model *model,float deep_dark);
Beer *hasen_init(Model *model,float deep_dark);
Beer *mayo_init(Model *model,float deep_dark);
Beer *cake_init(Model *model,float deep_dark);
	
void sinario_test(Model *model);
void sinario_intro(Model *model);
void sinario_uya(Model *model);
void sinario_0(Model *model);
void sinario_1(Model *model);
void sinario_2(Model *model);
void sinario_daas(Model *model);
void sinario_3(Model *model);
void sinario_cheese(Model *model);
void sinario_tired(Model *model);
void sinario_drink_energy(Model *model);
void sinario_4(Model *model);
void sinario_pancake(Model *model);
void sinario_sugar(Model *model);
void sinario_shunichel(Model *model);
void sinario_butter(Model *model);
void sinario_dinner(Model *model);
void sinario_5(Model *model);
void sinario_mayo(Model *model);
void sinario_milk(Model *model);
void sinario_putin(Model *model);
void sinario_6(Model *model);
void sinario_done();

void draw_background();

extern int cur_state;
const extern  int state_num;
extern GLenum state_list[3];
extern int cur_beer;
const extern int beer_num;
extern Beer *beer_list[50];

extern int timer;

#endif