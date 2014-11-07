#include "RayTracer.h"
#include "Scene3DParser.h"

RayTracer::RayTracer(std::string path) 
{
	Scene3DParser* scene_parser = new Scene3DParser(path);
	scene = scene_parser->parse();
}


RayTracer::~RayTracer(void)
{
}