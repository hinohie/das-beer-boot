#ifndef __METERIAL_H__
#define __METERIAL_H__

class Color{
public:
	float R,G,B,A;
	Color(){
		R=G=B=A = 1.0;
	}
	Color(float r, float g, float b, float a = 1.0)
	{
		R = r; G = g; B = b; A = a;
	}
	/*
	Color(int r, int g,int b,int a = 255)
	{
		R = (r / 255.0);
		G = (g / 255.0);
		B = (b / 255.0);
		A = (a / 255.0);
	}*/
	void setf(float r, float g,float b, float a = 1.0)
	{
		R = r; G = g; B = b; A = a;
	}
	void setd(int r, int g,int b,int a = 255)
	{
		R = (r / 255.0);
		G = (g / 255.0);
		B = (b / 255.0);
		A = (a / 255.0);
	}
	void copy(Color c)
	{
		R = c.R; G = c.G; B = c.B; A = c.A;
	}
};

class Meterial{
public:
	char* name;
	Color Ambient;
	Color Diffuse;
	Color Specular;
	float Ns;
	float d;
	float Tr;
	int illum;

	Meterial(){
		illum = 0;
	}
};

/**************** illum table ******************
0. Color on and Ambient off
1. Color on and Ambient on
2. Highlight on
3. Reflection on and Ray trace on
4. Transparency: Glass on, Reflection: Ray trace on
5. Reflection: Fresnel on and Ray trace on
6. Transparency: Refraction on, Reflection: Fresnel off and Ray trace on
7. Transparency: Refraction on, Reflection: Fresnel on and Ray trace on
8. Reflection on and Ray trace off
9. Transparency: Glass on, Reflection: Ray trace off
10. Casts shadows onto invisible surfaces
*************************************************/

#endif