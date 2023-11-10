#include "Move.h"
#include "Status.cpp"
#include "Stat.cpp"
#include "Type.cpp"
#include "Effect.h"
#include <iostream>
#include <vector>
#include <stdarg.h>
#pragma once
class Pokemon {
private:
    std::string name;
    std::vector<Type> types;
    Effect stage;
    Effect condition;
    std::vector<Effect> effects;
    int confusion;
    int level;
    double base[8];
public:
    Pokemon();
    Pokemon(std::string var1, int var2);
    void setLevel(int var1);
    void setStats(double var1, double var2, double var3, double var4, double var5, double var6);
    double getStat(Stat var1);
    bool hasType(Type var1);
    void addEffect(Effect var1);
    void setCondition(Effect var1);
    Status getCondition();
    void confuse();
    void restore();
    double getHP();
    void setMod(Stat var1, int var2);
    std::vector<Type> getTypes();
    int getLevel();
    double getAttackChance();
    bool isAlive();
    void turn();
    void setType(int n, Type var1, ...);
    void addType(Type var1);
protected:
    
};
