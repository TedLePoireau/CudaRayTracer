#include "Scene3DParser.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include "Sphere3D.h"

Scene3DParser::Scene3DParser(std::string path) :
	path(path) {}

Scene3D* Scene3DParser::parse()
{
	if (path.empty())
	{
		Scene3D *scene = new Scene3D(0, 0);
		return scene;
	}
	line_nb = 0;
	std::ifstream in(path);
	std::string line;
	Scene3D *scene = NULL;
	while (readline(in, line))
	{
		if (line.empty())
			continue;
		if (line.at(0) == '#')
			continue;

		if (line == "scene")
		{
			scene = parseScene(in);
		}
		else if (line == "light")
		{
			//parseLight(in, scene);
		}
		else if (line == "sphere")
		{
			parseSphere(in, scene);
		}
		else if (line == "plane")
		{
		}
	}
}



Scene3D* Scene3DParser::parseScene(std::ifstream& in)
{
	std::string line;
	int size_x = -1, size_y = -1;
	readline(in, line);
	if (line != "{")
	{
		std::cout << "[ERROR] Missing \"{\" at line : " << line_nb << std::endl;
		std::exit(-1);
	}
	std::string command;
	while (readline(in, line))
	{
		if (line == "}")
			break;
		command = *get_command(line);
		if (command == "size_x")
		{	size_x = std::stoi(*get_parameter(line)); }
		else if (command == "size_y")
		{	size_y = std::stoi(*get_parameter(line)); }
		else
		{
			std::cout << "[ERROR] Unrecognized parameter at line : " << line_nb << std::endl;
			std::exit(-1);
		}
	}
	if (size_x < 0)
	{
		std::cout << "[ERROR] Missing pos_x in Scene at line : " << line_nb << std::endl;
		std::exit(-1);
	}
	else if (size_y < 0)
	{
		std::cout << "[ERROR] Missing pos_y in Scene at line : " << line_nb << std::endl;
		std::exit(-1);
	}
	Scene3D* scene = new Scene3D(size_x, size_y);
	return scene;
}

void Scene3DParser::parseSphere(std::ifstream& in, Scene3D* scene)
{
	std::string line;
	int pos_x = -1, pos_y = -1, rayon = -1;
	readline(in, line);
	if (line != "{")
	{
		std::cout << "[ERROR] Missing \"{\" at line : " << line_nb << std::endl;
		std::exit(-1);
	}
	std::string command;
	while (readline(in, line))
	{
		if (line == "}")
			break;
		command = *get_command(line);
		if (command == "pos_x")
		{	pos_x = std::stoi(*get_parameter(line)); }
		else if (command == "pos_y")
		{	pos_y = std::stoi(*get_parameter(line)); }
		else if (command == "rayon")
		{	rayon = std::stoi(*get_parameter(line)); }
		else
		{
			std::cout << "[ERROR] Unrecognized parameter at line : " << line_nb << std::endl;
			std::exit(-1);
		}
	}
	if (pos_x < 0)
	{
		std::cout << "[ERROR] Missing or negative pos_x in Sphere at line : " << line_nb << std::endl;
		std::exit(-1);
	}
	else if (pos_y < 0)
	{
		std::cout << "[ERROR] Missing or negative pos_y in Sphere at line : " << line_nb << std::endl;
		std::exit(-1);
	}
	else if (rayon < 0)
	{
		std::cout << "[ERROR] Missing or negative rayon in Sphere at line : " << line_nb << std::endl;
		std::exit(-1);
	}
	Sphere3D* sphere = new Sphere3D(pos_x, pos_y, rayon);
	scene->addObject3D((Object3D*)sphere);
	return;
}

bool Scene3DParser::readline(std::ifstream& in, std::string& line)
{
	void* ret = std::getline(in, line);
	if (line.empty())
		return ret != nullptr;
	trim_string(line);
	line_nb++;
	return ret != nullptr;
}


void Scene3DParser::trim_string(std::string& s)
{
	auto it = s.begin(), end = s.end();
	end--;
	while ( (it != end) && ( (std::isspace(*it)) || (*it == '\t') ))
		it++;
	while ( (end != it) && std::isspace(*end) )
		end--;
	s.erase(++end, s.end());
	s.erase(s.begin(), it);

	return;
}

std::string* Scene3DParser::get_command(std::string& s)
{
	auto it = s.begin();
	auto end = s.end();
	while (it != end && *it != ':' && *it != ' ' && *it != '\t')
		it++;
	if (it == end)
	{
		std::cout << "[ERROR] Impossible to parse line : " << line_nb << std::endl;
		std::exit(-1);
	}
	std::string* cmd = new std::string(s.begin(), it);
	return cmd;
}

std::string* Scene3DParser::get_parameter(std::string& s)
{
	auto begin= s.begin();
	auto it = s.end();
	it--;
	while (it != begin && *it != ':' && *it != ' ' && *it != '\t')
		it--;
	if (it == begin)
	{
		std::cout << "[ERROR] Impossible to parse line : " << line_nb << std::endl;
		std::exit(-1);
	}
	std::string* param = new std::string(++it, s.end());
	return param;
}

Scene3DParser::~Scene3DParser(void)
{
}
