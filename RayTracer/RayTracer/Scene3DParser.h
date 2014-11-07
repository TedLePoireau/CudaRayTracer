#pragma once
#include "Scene3D.h"
#include <string>

class Scene3DParser
{
private:
	std::string path;
	unsigned int line_nb;

	Scene3D* parseScene(std::ifstream& in);
	void parseSphere(std::ifstream& in, Scene3D* scene);
	void parsePlane(std::ifstream& in, Scene3D* scene);
	//void parseLight(std::ifstream& in, Scene3D* scene);

	bool readline(std::ifstream& in, std::string& line);
	void trim_string(std::string& s);
	std::string* get_parameter(std::string& s);
	std::string* get_command(std::string& s);
public:
	Scene3DParser(std::string path);
	Scene3D* parse(void);
	~Scene3DParser(void);
};

