#pragma once
#include <string>
#include "Scene3D.h"
class RayTracer
{
private:
	Scene3D* scene;
public:
	RayTracer(std::string path);
	~RayTracer(void);
	int main(void);
};

