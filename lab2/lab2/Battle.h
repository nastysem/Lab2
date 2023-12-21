#include "Team.h"
#pragma once
class Battle {
private:
	std::shared_ptr<Team> allies;
	std::shared_ptr<Team> foes;
	std::string allyName;
	std::string foeName;
	bool checkFirst(std::shared_ptr<Pokemon>(var1), std::shared_ptr<Pokemon>(var2));
public:
	Battle();
	void addAlly(std::shared_ptr<Pokemon>(var1));
	void addFoe(std::shared_ptr<Pokemon>(var1));
	void go();
};