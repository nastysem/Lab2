class Pokemon;
#include <iostream>
#pragma once
class Effect {
private:
	int mods[8];
	int turns = 0;
	double effectChance = 1.0;
	double attackChance = 1.0;
	Status conditions;
	
public:
	Effect();
	~Effect();
	Effect setTurns(int var1);
	Effect chance(double var1);
	Effect attacks(double var1);
	double attack();
	Effect condition(Status var1);
	void clear();
	Status status();
	int stat(Stat var1);
	Effect stats(Stat var1, int var2);
	bool success();
	bool immediate();
	bool turn();
	static void burn(Pokemon &p);
	static void paralyze(Pokemon &p);
	static void freeze(Pokemon& p);
	static void poison(Pokemon& p);
	static void sleep(Pokemon& p);
	static void flinch(Pokemon& p);
	static void confuse(Pokemon& p);
};
