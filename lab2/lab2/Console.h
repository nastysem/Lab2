#include <iostream>
#include "Battle.h"
#include "Nidoqueen.h"
#include "Hitmonlee.h"
#include "Throh.h"
#pragma once
class Console {
private:
	void info();
	Battle b;
	void choose1(int var1);
	void choose2(int var1);
	int choice;
	int level;
	std::string name;
public:
	void game();
};
