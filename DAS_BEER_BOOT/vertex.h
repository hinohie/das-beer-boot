#ifndef __VERTEX_H__
#define __VERTEX_H__

class vector3f{
public:
	float X,Y,Z;
	vector3f(float x = 0.0, float y = 0.0, float z = 0.0)
	{
		X = x; Y = y; Z = z;
	}
	void set(float x = 0,float y = 0.0, float z = 0)
	{
		X = x; Y = y; Z = z;
	}
	void copy(vector3f nc)
	{
		X = nc.X; Y = nc.Y; Z = nc.Z;
	}
};
class vector4f{
public:
	float X,Y,Z,W;
	vector4f(float x = 0.0, float y = 0.0, float z = 0.0, float w = 0.0)
	{
		X = x; Y = y; Z = z; W = w;
	}
	void set(float x = 0,float y = 0.0, float z = 0, float w = 0.0)
	{
		X = x; Y = y; Z = z; W = w;
	}
	void copy(vector4f nc)
	{
		X = nc.X; Y = nc.Y; Z = nc.Z; W = nc.W;
	}
};

class Vertex{
public:
	vector4f coord;
	Vertex(float x = 0.0, float y = 0.0, float z = 0.0, float w = 0.0)
	{
		coord.set(x,y,z,w);
	}
};
class Vertex_normal{
public:
	vector3f normal;
	Vertex_normal(float x = 0.0, float y = 0.0, float z = 0.0)
	{
		normal.set(x,y,z);
	}
};
class Vertex_texture{
public:
	vector3f texture_coord;
	Vertex_texture(float x = 0.0, float y = 0.0, float z = 0.0)
	{
		texture_coord.set(x,y,z);
	}
};
class Vertex_param{
public:
	vector3f vp;
	Vertex_param(float x = 0.0, float y = 0.0, float z = 0.0)
	{
		vp.set(x,y,z);
	}
};

#endif