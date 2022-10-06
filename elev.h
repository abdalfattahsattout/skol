#pragma once
#include <string>

class elev {
public:
	elev(std::string namn2, int age2) {
		elev::namn = namn2;
		age = age2;
	}
	std::string namn;
	int age;
};
