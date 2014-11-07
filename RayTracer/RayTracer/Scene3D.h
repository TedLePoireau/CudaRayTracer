#pragma once
#include <list>
#include "Object3D.h"
#include "Light.h"
class Scene3D
{
private:
	std::list<Object3D*> objects;
	std::list<Light> lights;
	int size_x, size_y;
public:
	Scene3D(unsigned int size_x, unsigned int size_y);
	void addLight(Light light);
	void addObject3D(Object3D* object);
};

