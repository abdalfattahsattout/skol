#pragma once
#include <vector>
#include <iostream>
#include "elev.h"
#include "klass.h"
class schoolsystem
{
public: 
	void start();
	void Add(std::string name, int age);
	void removee(std::string name);
	void infostudentt(std::string name);
	void changeclass(std::string name, std::string nyKlass);
	bool serchstudent(std::string name);
	void removestudentclass(std::string name);
	void classinfo(std::string klass);
	void createclass(std::string namn);

private:
	std::vector<elev> elever;
	std::vector<klass> klasser;
};