class Pokemon;
#include "Type.cpp"
#include <iostream>
#pragma once
class Move {
private:
protected:
	int effects[19][19];
	Type type;
	double power;
	double accuracy;
	int priority;
	int hits;
	virtual bool checkAccuracy(Pokemon& var1, Pokemon& var2);
	virtual void applyOppEffects(Pokemon& var1);
	virtual void applySelfEffects(Pokemon& var1);
	virtual double effect(Type var1) final;
	virtual void setX(int var1, Type var2) final;
	virtual Type zero(int n, Type var1, ...) final;
	virtual Type half(int n, Type var1, ...) final;
	virtual Type doub(int n, Type var1, ...) final;
	virtual double getEffect(int n, Type var1, ...) final;
	virtual double getEffectForPokemon(Pokemon& var1) final;
	virtual void setEffect() final;
	virtual std::string describe();
public:
	virtual void attack(Pokemon& var1, Pokemon& var2) = 0; //внимательно тут
	Move();
	virtual ~Move();
	Move(Type var1, double var2, double var4);
	Move(Type var1, double var2, double var4, int var6, int var7);
	virtual int getPriority() final;
};