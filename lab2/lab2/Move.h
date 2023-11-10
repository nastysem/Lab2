class Pokemon;
#include "Type.cpp"
#pragma once
class Move {
private:
	static Move noMove;
	static Move struggleMove;
	static Move confusionMove;
protected:
	Type type;
	double power;
	double accuracy;
	int priority;
	int hits;
	bool checkAccuracy(Pokemon var1, Pokemon var2);
	virtual void attack(Pokemon var1, Pokemon var2) = 0; //внимательно тут
	void applyOppEffects(Pokemon var1);
	void applySelfEffects(Pokemon var1);
	//describe

public:
	Move();
	//деструктор
	Move(Type var1, double var2, double var4);
	Move(Type var1, double var2, double var4, int var6, int var7);
	int getPriority();
	static Move getNoMove();
	static Move getSruggleMove();
	static Move getConfusionMove();

};