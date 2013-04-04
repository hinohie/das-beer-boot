#include <stdlib.h>
#include <glut.h>

#include "funccollect.h"

void draw_Vertex(Model *model)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for(int i=0; i<model->vv_list.size(); i++)
	{
		glVertex3f(model->vv_list[i]->coord.X, model->vv_list[i]->coord.Y, model->vv_list[i]->coord.Z);
	}
	glEnd();
}
void draw_Line(Model *model)
{
	glColor3f(1.0, 1.0, 1.0);
	for(int i=0; i<model->objects.size(); i++)
	{
		Object *obj = model->objects[i];
		for(std::list<Flag>::iterator it = obj->flags.begin(); it != obj->flags.end(); it++)
		{
			glBegin(GL_LINE_LOOP);
			for(int j=0; j<it->vv.size(); j++)
			{
				glVertex3f(it->vv[j]->coord.X, it->vv[j]->coord.Y, it->vv[j]->coord.Z);
			}
			glEnd();
		}
	}
}
void draw_Flag(Model *model)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
	for(int i=0; i<model->objects.size(); i++)
	{
		Object *obj = model->objects[i];
		for(std::list<Flag>::iterator it = obj->flags.begin(); it != obj->flags.end(); it++)
		{
			for(int j=1; j<it->vv.size()-1; j++)
			{
				glVertex3f(it->vv[0]->coord.X, it->vv[0]->coord.Y, it->vv[0]->coord.Z);
				glVertex3f(it->vv[j]->coord.X, it->vv[j]->coord.Y, it->vv[j]->coord.Z);
				glVertex3f(it->vv[j+1]->coord.X, it->vv[j+1]->coord.Y, it->vv[j+1]->coord.Z);
			}
		}
	}
	glEnd();
}
void draw(Model *model,GLenum type, Beer *beer = NULL)
{
	float deep_dark;
	if(beer != NULL)
		deep_dark = beer->deep_dark_rate;
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	for(int i=0; i<model->objects.size(); i++)
	{
		Object *obj = model->objects[i];
		int k=0;
		for(std::list<Flag>::iterator it = obj->flags.begin(); it != obj->flags.end(); it++)
		{
			glPolygonMode(GL_FRONT, type);
			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_POLYGON);
			for(int j=0; j<it->vv.size(); j++)
			{
				glVertex3f(it->vv[j]->coord.X + model->center.X, it->vv[j]->coord.Y + model->center.Y, it->vv[j]->coord.Z + model->center.Z);
			}
			glEnd();
			if(beer != NULL) {
			/*		Fill glass with beer	 */
			glColor4f(beer->color_list[k].R,beer->color_list[k].G,beer->color_list[k].B, beer->color_list[k].A);
			glPolygonMode(GL_FRONT, GL_FILL);
			glBegin(GL_POLYGON);
			for(int j=0; j<it->vv.size(); j++)
			{
				glVertex3f(it->vv[j]->coord.X + model->center.X - it->vn[j]->normal.X * deep_dark, it->vv[j]->coord.Y + model->center.Y - it->vn[j]->normal.Y * deep_dark, it->vv[j]->coord.Z + model->center.Z - it->vn[j]->normal.Z * deep_dark);
			}
			glEnd();
			}
			k++;
		}
	}
}