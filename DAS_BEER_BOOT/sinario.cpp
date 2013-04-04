#include <stdlib.h>
#include <glut.h>

#include "funccollect.h"

float rotate = 0;
int dine;
void sinario_test(Model *model)
{
	float scale = 1.0;
	gluLookAt(70 * sin(rotate), 30, 70 * cos(rotate),
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[cur_state],beer_list[15]);

	glPopMatrix();
	glutSwapBuffers();
	
	if(timer > 1000)
	{
		timer = 0;
		cur_state = (cur_state + 1)%state_num;
	}
}
void sinario_intro(Model *model)
{
	float scale = 1.0;
	gluLookAt(30 * sin(rotate), 100 - rotate*12, 30 * cos(rotate),
		      0, 100 - rotate*12, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[1], beer_list[2]);

	glPopMatrix();
	glutSwapBuffers();
	
	rotate += 0.01;
	if(timer > 1000)
	{
		timer = 0;
		rotate += 0.1;
	}
}
void sinario_uya(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	if(timer > 500)
		rotate = 1;
	draw(model, state_list[1], rotate>0.5?beer_list[4]:NULL);

	glPopMatrix();
	glutSwapBuffers();
	
	rotate = 0;
}
void sinario_0(Model *model)
{
	float scale = 1.0;
	gluLookAt(70 * sin(rotate), 30, 70 * cos(rotate),
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[cur_state], NULL);

	glPopMatrix();
	glutSwapBuffers();
	
	rotate += 0.01;
	if(timer > 1000)
	{
		timer = 0;
		cur_state = (cur_state + 1)%state_num;
	}
	dine = 0;
}
void sinario_1(Model *model)
{
	float scale = 1.0;
	gluLookAt(70 * sin(rotate), 30, 70 * cos(rotate),
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[cur_state], beer_list[4]);

	glPopMatrix();
	glutSwapBuffers();
	
	rotate += 0.01;
	if(timer > 1000)
	{
		timer = 0;
		cur_state = (cur_state + 1)%state_num;
	}
}
void sinario_2(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	for(int i=0; i<=cur_beer; i++)
	{
		Model *nm = new Model(*model);
		nm->setcenter(vector3f(70 - 35*i, i*5 - 10, 15*i - 25));
		draw(nm, state_list[1], beer_list[i]);
		free(nm);
	}

	glPopMatrix();
	glutSwapBuffers();
	
	rotate += 0.01;
	if(cur_beer< 2 && timer > 200)
	{
		timer = 0;
		cur_beer ++;
	}
	else if( cur_beer >1 && timer > 550)
	{
		timer = 0;
		if(dine < 1)
		{
			dine ++ ;
			cur_beer = 0;
		}
		else
		{
			dine = -1;
			cur_beer = (cur_beer + 1)%beer_num;
		}
	}
}
void sinario_daas(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[1], beer_list[1]);

	glPopMatrix();
	glutSwapBuffers();
}
void sinario_3(Model *model)
{
	float scale = 1.0;
	gluLookAt(60, 30, 70,
		      58, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[1], beer_list[6]);
	Model *nm = new Model(*model);
	nm->setcenter(vector3f(110, -50, 55));
	draw(nm, state_list[1], beer_list[6]);
	free(nm);

	glPopMatrix();
	glutSwapBuffers();
}

void draw_cheese()
{
	float sx, sy, sw, sr;
	float i, j, k;

	sx = -70;
	sy = 150;
	sw = 20;
	sr = timer/100.0;
	glPushMatrix();
	glColor3f(0.92, 0.672, 0.313);
	for(i=0; i<timer*1.5; i++)
	{
		j = sw * exp(-i / sr);
		k = sw * exp((-i-1) / sr);
		glBegin(GL_POLYGON);
		glVertex3f(sx - k, sy - i-1, 0);
		glVertex3f(sx + k, sy - i-1, 0);
		glVertex3f(sx + j, sy - i, 0);
		glVertex3f(sx - j, sy - i, 0);
		glEnd();
	}

	glPopMatrix();
}
void sinario_cheese(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  0, 0.707, 0.707);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[1], beer_list[8]);

	beer_list[8]->deep_dark_rate += 0.08;

	if(beer_list[8] ->deep_dark_rate > 10)
		beer_list[8] ->deep_dark_rate = 10;
	glPopMatrix();
	draw_cheese();

	rotate = 0;
	glutSwapBuffers();
}
void sinario_tired(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  sin(rotate), cos(rotate), 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[1], beer_list[8]);

	glPopMatrix();

	rotate += 0.01;

	glutSwapBuffers();
	dine = 0;
}

void sinario_drink_energy(Model *model)
{
	
	float scale = 1.0;
	gluLookAt(0, 30, 70 - dine * 7,
		      0, 20, 0,
			  dine / 5.0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	int dfd;
	if(dine == 6)
	dfd = -1;
	else
	{
		if(dine > 3)
			dfd = 9;
		else
			dfd = 12 - dine;
	}
	draw(model, state_list[1], dfd < 0 ? NULL : beer_list[dfd]);
	if( timer > 600)
	{
		timer = 0;
		dine ++;
	}

	glPopMatrix();

	glutSwapBuffers();
}
void sinario_4(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 50, 0,
			  -1, 0, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[1], beer_list[5]);

	glPopMatrix();
	glutSwapBuffers();
	
	beer_list[5]->deep_dark_rate -= 0.01;
	if(timer > 4000)
	{
		beer_list[5]->deep_dark_rate -= 0.08;
	}
	if(timer > 6000)
	{
		beer_list[5]->deep_dark_rate -= 0.18;
	}
	if(timer > 7000)
	{
		beer_list[5]->deep_dark_rate -= 0.18;
	}
	if(timer > 7500)
	{
		beer_list[5]->deep_dark_rate += 1.48;
	}
}

void sinario_pancake(Model *model)
{
	
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	draw(model, state_list[1], beer_list[dine + 13]);
	if(dine < 3 && timer > 550)
	{
		timer = 0;
		dine ++;
	}
	glPopMatrix();
	glPushMatrix();
	gluLookAt(0,30, 70,
		      0, 20, 0,
			  timer / 500.0, 1, 0);
	Model *nm = new Model(*model);
	nm->center.X = -120;
	draw(nm, state_list[1], NULL);
	free(nm);
	glPopMatrix();
	glPushMatrix();
	gluLookAt(0,30, -70,
		      0, 20, 0,
			  timer / 500.0, 1, 0);
	nm = new Model(*model);
	nm->center.X = -120;
	draw(nm, state_list[1],NULL);
	free(nm);
	glPopMatrix();

	glutSwapBuffers();
}
void sinario_sugar(Model *model)
{
	
	float scale = 1.0;
	Model *nm;

	glPushMatrix();
	gluLookAt(0, 80, 70,
		      0, 70, 0,
			  0, 1, 0);
	glScalef(scale, scale, scale);

	nm = new Model(*model);
	nm->center.X = - 50;
	draw(nm, state_list[1],beer_list[16]);
	free(nm);
	nm = new Model(*model);
	nm->center.X = - 10;
	draw(nm, state_list[1],beer_list[15]);
	free(nm);
	nm = new Model(*model);
	nm->center.X = 30;
	draw(nm, state_list[1],beer_list[14]);
	free(nm);
	nm = new Model(*model);
	nm->center.X = 70;
	draw(nm, state_list[1],beer_list[13]);
	free(nm);
	
	glPopMatrix();
	glPushMatrix();
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  0, -1, 0);
	glScalef(scale, scale, scale);

	nm = new Model(*model);
	nm->center.X = - 70;
	nm->center.Y = -120;
	draw(nm, state_list[1],beer_list[18]);
	free(nm);
	nm = new Model(*model);
	nm->center.X = 70;
	nm->center.Y = -120;
	draw(nm, state_list[1],beer_list[17]);
	free(nm);

	glPopMatrix();

	glutSwapBuffers();
}
void sinario_shunichel(Model *model)
{
	float scale = 1.0;
	gluLookAt(70 * sin(rotate), 80, 70 * cos(rotate),
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	glBegin(GL_POLYGON);
	for(int i=0; i<20; i++)
	{
		glColor3b(140/2+i, 117/2 + i, 110/2 - i);
		glVertex3d( 70 * sin(i / 1.0) , 40 * cos(i / 21.0), 70 * cos(i/1.0));
	}
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
	
	rotate += 0.05;
	dine = 0;
}

void sinario_butter(Model *model)
{
	float scale = 1.0;
	gluLookAt(-100 * sin(rotate), 80, 100 * cos(rotate),
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);

	Model *nm = new Model(*model);
	nm->center.X = - 50;
	nm->center.Z = -50;
	draw(nm, state_list[1], beer_list[4]);
	free(nm);

	glBegin(GL_POLYGON);
	for(int i=0; i<20; i++)
	{
		glColor3b(140/2+i, 117/2 + i, 110/2 - i);
		glVertex3d( 70 * sin(i / 1.0) , 40 * cos(i / 21.0), 70 * cos(i/1.0));
	}
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
	
	rotate += 0.01;
	dine = 0;
}
void sinario_dinner(Model *model)
{
	
	float scale = 1.0;
	gluLookAt(70 * sin(rotate), 30, 70 * cos(rotate),
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);
	draw(model, state_list[1], beer_list[0]);
	glPopMatrix();
	glutSwapBuffers();
	
	rotate -= 0.07;
	dine = 0;
}

void sinario_5(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);
	Model *nm;

	for(int i=0; i<5; i++)
	{
		nm = new Model(*model);
		nm->setcenter(vector3f(70 + 140*i - timer/4.6, 0, 0));
		draw(nm, state_list[1], beer_list[i+19]);
		free(nm);
	}

	rotate = 0;
	glPopMatrix();
	glutSwapBuffers();
}
void sinario_mayo(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);
	Model *nm;
	nm = new Model(*model);
	nm->setcenter(vector3f(0, -60, 30));
	draw(nm, state_list[1], beer_list[24]);
	free(nm);

	rotate = 0;
	glPopMatrix();
	glutSwapBuffers();
}

void draw_cake(float sy = 20)
{
	float sx, sz;
	float r, dz;
	int i, j;
	float p = acos(0.0) * 2;

	sx = -90;
	sz = 0;
	dz = 5;
	r = 20;
	glColor3f(0.27, 0.204, 0.24);
	glBegin(GL_POLYGON);
	for(i=0; i<10; i++)
	{
		glVertex3f(sx + r*cos((i * 18) / p),sy, sz + r*sin((i * 18) / p));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for(i=0; i<10; i++)
	{
		glVertex3f(sx + r*cos(-(i * 18) / p),sy+dz+dz, sz + r*sin(-(i * 18) / p));
	}
	glEnd();
	glColor3f(0.97, 0.94, 0.94);
	glBegin(GL_POLYGON);
	for(i=0; i<10; i++)
	{
		glVertex3f(sx + r*cos((i * 18) / p),sy+dz, sz + r*sin((i * 18) / p));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for(i=0; i<10; i++)
	{
		glVertex3f(sx + r*cos(-(i * 18) / p),sy+dz+dz, sz + r*sin(-(i * 18) / p));
	}
	glEnd();
	glColor3f(0.27, 0.204, 0.24);
	glBegin(GL_POLYGON);
	for(i=0; i<10; i++)
	{
		glVertex3f(sx + r*cos((i * 18) / p),sy+dz+dz, sz + r*sin((i * 18) / p));
	}
	glEnd();
	glBegin(GL_POLYGON);
	for(i=0; i<10; i++)
	{
		glVertex3f(sx + r*cos(-(i * 18) / p),sy+dz+dz, sz + r*sin(-(i * 18) / p));
	}
	glEnd();
}
void sinario_milk(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 60, 70,
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);
	Model *nm;
	nm = new Model(*model);
	nm->setcenter(vector3f(0, 0, 0));
	draw(nm, state_list[1], beer_list[24]);
	free(nm);

	draw_cake(20);

	rotate = 0;
	dine = 0;
	glPopMatrix();
	glutSwapBuffers();
}
void sinario_putin(Model *model)
{
	float scale = 1.0;
	gluLookAt(0, 30, 70,
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);
	draw(model, state_list[1], beer_list[24 + dine]);

	rotate += 0.3;
	if(dine == 0)
		draw_cake(0 + rotate);
	if(timer > 1000)
		dine = 1;
	glPopMatrix();
	glutSwapBuffers();
}
int cur_boot = 0;
void sinario_6(Model *model)
{
	float scale = 1.0;
	gluLookAt( 70 * sin(rotate), 30, 70 * cos(rotate),
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);
	draw(model, state_list[1], beer_list[cur_boot]);

	if(dine == 1)
		rotate += 0.01;
	else if (dine == 2)
		rotate -= 0.05;
	else
		rotate += 0.03;
	if(timer > 200)
	{
		cur_boot++;
		if(cur_boot == 26 ) cur_boot = 0;
		timer -= 200;
		if(dine == 3)dine = 0;
		dine ++;
	}
	glPopMatrix();
	glutSwapBuffers();
}

void sinario_done()
{
	float scale = 1.0;
	gluLookAt(70, 30, 70,
		      0, 20, 0,
			  0, 1, 0);
	glPushMatrix();
	glScalef(scale, scale, scale);
	glPointSize(10.0);
	glColor3f(1.0, 0.2, 1.0);
	glBegin(GL_POINTS);
		glVertex3f(0, 0, 0);
	glEnd();

	glPopMatrix();
	
	glutSwapBuffers();
}
