#include "Pokemon.h"
#include <queue>
#pragma once
class Team {
public:
	Team();
	Team(std::string var1);
	void add(std::shared_ptr<Pokemon> var1);
	std::shared_ptr<Pokemon> next();
	bool hasNext();
	std::shared_ptr<Pokemon> poke();
	std::string getName();
private:
	std::queue<std::shared_ptr<Pokemon>> team;
	std::shared_ptr<Pokemon> pokemon;
	std::string name;
};
