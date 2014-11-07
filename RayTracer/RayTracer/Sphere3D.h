#pragma once
#include "Object3D.h"

class Sphere3D : Object3D
{
	unsigned int rayon;
public:
	Sphere3D(unsigned int x, unsigned int y, unsigned int rayon);
	~Sphere3D(void);
};

