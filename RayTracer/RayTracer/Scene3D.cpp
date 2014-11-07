#include "Scene3D.h"


Scene3D::Scene3D(unsigned int size_x, unsigned int size_y) :
	size_x(size_x), size_y(size_y), objects(), lights() {}

void Scene3D::addLight(Light light)
{
	lights.push_front(light);
}

void Scene3D::addObject3D(Object3D* object)
{
	objects.push_front(object);
}


