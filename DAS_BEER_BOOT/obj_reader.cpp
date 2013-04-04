#include <stdio.h>
#include "funccollect.h"
#include <string.h>

#define MAX_BUF 256

FILE *fp1, *fp2;
void parsing_mtl(Model* model)
{
	char buf[MAX_BUF];
	char command[10];
	char elc[MAX_BUF];
	char *name = "";
	float elf;
	float r,g,b;
	int eli;
	int len;

	Meterial *mtl = NULL;

	while(fgets(buf, MAX_BUF, fp2) > 0)
	{
		len = strlen(buf);

		if(sscanf(buf, "%s",command) <= 0)continue;
		if(strcmp(command, "newmtl") == 0) {
			if( mtl != NULL)
				model->meterial_map.insert(std::pair<char*, Meterial*>(mtl->name,mtl));
			int i, j;
			elc[0] = 0;
			for(i=7; i<len; i++)
				elc[i-7] = buf[i];
			elc[len-8] = 0;
			mtl = new Meterial();
			mtl->name = (char*)malloc(sizeof(char) * len-7);
			strcpy(mtl->name ,elc);
		}
		else if(strcmp(command, "Ns") == 0){
			sscanf(buf, "\tNs %f", &elf);
			mtl->Ns = elf;
		}
		else if(strcmp(command, "d") == 0){
			sscanf(buf, "\td %f", &elf);
			mtl->d = elf;
		}
		else if(strcmp(command, "Tr") == 0){
			sscanf(buf, "\tTr %f", &elf);
			mtl->Tr = elf;
		}
		else if(strcmp(command, "illum") == 0){
			sscanf(buf, "\tillum %d", &eli);
			mtl->illum = eli;
		}
		else if(strcmp(command, "Ka") == 0){
			sscanf(buf,"\tKa %f %f %f",&r,&g,&b);
			mtl->Ambient.setf(r,g,b);
		}
		else if(strcmp(command, "Kd") == 0){
			sscanf(buf,"\tKd %f %f %f",&r,&g,&b);
			mtl->Diffuse.setf(r,g,b);
		}
		else if(strcmp(command, "Ks") == 0){
			sscanf(buf,"\tKs %f %f %f",&r,&g,&b);
			mtl->Specular.setf(r,g,b);
		}
	}
	if( mtl != NULL)
		model->meterial_map.insert(std::pair<char*, Meterial*>(mtl->name,mtl));
}
void parsing_obj(Model* model)
{
	char buf[MAX_BUF];
	char command[10];
	char elc[MAX_BUF];
	float elf;
	float x,y,z,w;
	int len;
	int jusuck_count = 0;

	int cur_obj = -1;
	Object *obj = NULL;

	while(fgets(buf, MAX_BUF, fp1) > 0)
	{
		len = strlen(buf);
		if(len>0 && buf[0] == '#')
		{
			jusuck_count ++;
			continue;
		}
		else{ jusuck_count = 0;}

		if(sscanf(buf,"%s",command) <= 0) continue;

		if(strcmp(command, "mtllib") == 0)	{
			int i, j;
			elc[0] = 0;
			for(i=7; i<len; i++)
				elc[i-7] = buf[i];
			elc[len-8] = 0;
			fp2 = fopen(elc,"rt");
			parsing_mtl(model);
		}
		else if(strcmp(command, "v") == 0) {
			int i, j, k;
			int offset=0;
			float v[5];
			Vertex *vv;
			while(buf[offset]!='v')offset++;
			offset++;
			while(buf[offset]=='\t' || buf[offset] == 32) offset++;
			for(i=0; offset<len; i++,offset++)
			{
				for(j=0;buf[offset]!=32 && buf[offset] != 10 && buf[offset] != '\t' && buf[offset]>0; j++,offset++)
					elc[j] = buf[offset];
				if(j==0)break;
				elc[j] = 0;
				sscanf(elc,"%f",&v[i]);
			}
			switch(i)
			{
			case 0:
				vv = new Vertex();
				break;
			case 1:
				vv = new Vertex(v[0]);
				break;
			case 2:
				vv = new Vertex(v[0],v[1]);
				break;
			case 3:
				vv = new Vertex(v[0],v[1],v[2]);
				break;
			case 4:
				vv = new Vertex(v[0],v[1],v[2],v[3]);
				break;
			}
			model->vv_list.push_back(vv);
		}
		else if(strcmp(command, "vt") == 0) {
			int i, j, k;
			int offset = 0;
			float v[5];
			Vertex_texture *vt;
			while(buf[offset]!='t')offset++;
			offset++;
			while(buf[offset]=='\t' || buf[offset] == 32) offset++;
			for(i=0; offset<len; i++,offset++)
			{
				for(j=0;buf[offset]!=32 && buf[offset] != 10 && buf[offset] != '\t' && buf[offset]>0; j++,offset++)
					elc[j] = buf[offset];
				if(j==0)break;
				elc[j] = 0;
				sscanf(elc,"%f",&v[i]);
			}
			switch(i)
			{
			case 0:
				vt = new Vertex_texture();
				break;
			case 1:
				vt = new Vertex_texture(v[0]);
				break;
			case 2:
				vt = new Vertex_texture(v[0],v[1]);
				break;
			case 3:
				vt = new Vertex_texture(v[0],v[1],v[2]);
				break;
			}
			model->vt_list.push_back(vt);
		}
		else if(strcmp(command, "vn") == 0) {
			int i, j, k;
			int offset = 0;
			float v[5];
			Vertex_normal *vn;
			while(buf[offset]!='n')offset++;
			offset++;
			while(buf[offset]=='\t' || buf[offset] == 32) offset++;
			for(i=0; offset<len; i++,offset++)
			{
				for(j=0;buf[offset]!=32 && buf[offset] != 10 && buf[offset] != '\t' && buf[offset]>0; j++,offset++)
					elc[j] = buf[offset];
				if(j==0)break;
				elc[j] = 0;
				sscanf(elc,"%f",&v[i]);
			}
			switch(i)
			{
			case 0:
				vn = new Vertex_normal();
				break;
			case 1:
				vn = new Vertex_normal(v[0]);
				break;
			case 2:
				vn = new Vertex_normal(v[0],v[1]);
				break;
			case 3:
				vn = new Vertex_normal(v[0],v[1],v[2]);
				break;
			}
			model->vn_list.push_back(vn);
		}
		else if(strcmp(command, "vp") == 0) {
			int i, j, k;
			int offset = 0;
			float v[5];
			Vertex_param *vp;
			while(buf[offset]!='p')offset++;
			offset++;
			while(buf[offset]=='\t' || buf[offset] == 32) offset++;
			for(i=0; offset<len; i++,offset++)
			{
				for(j=0;buf[offset]!=32 && buf[offset] != 10 && buf[offset] != '\t' && buf[offset]>0; j++,offset++)
					elc[j] = buf[offset];
				if(j==0)break;
				elc[j] = 0;
				sscanf(elc,"%f",&v[i]);
			}
			switch(i)
			{
			case 0:
				vp = new Vertex_param();
				break;
			case 1:
				vp = new Vertex_param(v[0]);
				break;
			case 2:
				vp = new Vertex_param(v[0],v[1]);
				break;
			case 3:
				vp = new Vertex_param(v[0],v[1],v[2]);
				break;
			}
			model->vp_list.push_back(vp);
		}
		
		else if(strcmp(command, "g") == 0) {
			cur_obj++;
			obj = new Object();
			model->objects.push_back(obj);
			model->objects[cur_obj]->name = (char*) malloc(sizeof(char) * (len - 2));
			sscanf(buf, "g %s",model->objects[cur_obj]->name);
		}
		else if(strcmp(command, "usemtl") == 0) {
			sscanf(buf, "usemtl %s",elc);
			std::map<char*, Meterial*>::iterator it;
			for(it = model->meterial_map.begin(); it != model->meterial_map.end(); it++)
				if(strcmp(elc,it->first) == 0)
					break;
			if(it != model->meterial_map.end())
				model->objects[cur_obj]->mtl = it->second;
		}
		else if(strcmp(command, "s") == 0) {
			sscanf(buf, "s %s",elc);
			if(strlen(elc)>1)
				obj->smooth = false;
			else
				obj->smooth = true;
		}
		else if(strcmp(command, "f") == 0) {
			Flag flag;
			int v[3] = {0,0,0};
			int offset = 2;
			if(model->objects[cur_obj]->flags.size() > 54)
				offset = 2;
			while(1)
			{
				int i, j, k, l=0;
				for(j=0; offset<len; j++,offset++)
				{
					if(buf[offset] == 32 || buf[offset] == 10 || buf[offset] == '\t')
						break;
					elc[j] = buf[offset];
				}
				if(offset == len || j == 0)break;
				offset++;;
				elc[j] = 0;
				k=0;
				for(i=0; i<=j; i++)
				{
					if(i==j || elc[i] == '/')
					{
						v[l++] = k;
						k=0;
					}
					else
					{
						k*=10;
						k+=(elc[i] - '0');
					}
				}
				if(v[0]>0)
					flag.vv.push_back( model->vv_list[v[0]-1] );
				if(v[1]>0)
					flag.vt.push_back( model->vt_list[v[1]-1] );
				if(v[2]>0)
					flag.vn.push_back( model->vn_list[v[2]-1] );
			}
			model->objects[cur_obj]->flags.push_back(flag);
		}
	}
}

Model *getModel(const char* src)
{
	fp1 = fopen(src,"rt");

	if(fp1 == NULL)return NULL;

	Model *result = new Model();

	parsing_obj(result);

	return result;
}


void PRINT(Flag flag)
{
	printf("\t\t\t");
	for(int i=0; i<flag.vv.size(); i++)
	{
		printf("%f ",flag.vv[i]->coord.X);
	}
	printf("\n");
}
void PRINT(Object *obj)
{
	printf("\t\tobject name	  = %s\n",obj->name);
	printf("\t\tmeterial name = %s\n",obj->mtl->name);
	printf("\t\tsmooth        = %d\n",obj->smooth);
	printf("\t\tflags size    = %d\n",obj->flags.size());
	for(std::list<Flag>::iterator it = obj->flags.begin(); it != obj->flags.end(); it++)
	{
//		PRINT(*it);
	}
}
void PRINT(Model *model)
{
	int i, j;
	printf("/** model **/\n");
	printf("\tobject count   = %d\n",model->objects.size());
	for(i=0; i<model->objects.size(); i++)
	{
		Object *obj = model->objects[i];
		PRINT(obj);
	}
	printf("\tmeterial count = %d\n",model->meterial_map.size());
	printf("\tvertex count   = %d\n",model->vv_list.size());
	printf("\tvertex T count = %d\n",model->vt_list.size());
	printf("\tvertex N count = %d\n",model->vn_list.size());
}

