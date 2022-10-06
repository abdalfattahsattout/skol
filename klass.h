#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "elev.h"

class klass {
public:
	void addtoo(elev elev);
	void removefrome(elev elev);
	void seestudent();
	std::string namn;
	std::vector<elev> elever;
private:
};
