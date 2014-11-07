#include "Object3D.h"

Object3D::Object3D(unsigned int x, unsigned int y) :
	x(x), y(y) {}

std::pair<int,int> Object3D::getPos() 
{
	return std::pair<int,int>(x, y);
}