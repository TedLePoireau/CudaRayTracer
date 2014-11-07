#pragma once
#include <tuple>

class Object3D
{
private:
	unsigned int x;
	unsigned int y;
public:
	Object3D (unsigned int x, unsigned int y);
	std::pair<int,int> getPos();


};