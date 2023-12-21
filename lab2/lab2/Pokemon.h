#include "StruggleMove.h"
#include "NoMove.h"
#include "ConfusionMove.h"
#include "Status.cpp"
#include "Stat.cpp"
#include "Type.cpp"
#include "StruggleMove.h"
#include "NoMove.h"
#include "ConfusionMove.h"
#include "Status.cpp"
#include "Stat.cpp"
#include "Type.cpp"
#include "Effect.h"
#include <iostream>
#include <vector>
#include <stdarg.h>
#include <string>
#include "Writer.h"
#pragma once
class Pokemon {
private:
    std::string name;
    std::vector<Type> types;
    Effect stage;
    Effect condition;
    std::vector<Effect> effects;
    std::vector<std::shared_ptr<Move>> moves;
    std::shared_ptr<Move> preparedMove;
    int confusion;
    int level;
    double base[8];
    double getAttackChance();
public:
    Pokemon();
    Pokemon(std::string var1, int var2);
    virtual ~Pokemon();
    virtual void setLevel(int var1) final;
    virtual void setStats(double var1, double var2, double var3, double var4, double var5, double var6) final;
    virtual double getStat(Stat var1) final;
    virtual bool hasType(Type var1) final;
    virtual void addEffect(Effect var1) final;
    virtual void setCondition(Effect var1) final;
    virtual Status getCondition() final;
    virtual void confuse() final;
    virtual void restore() final;
    virtual double getHP() final;
    virtual void setMod(Stat var1, int var2) final;
    virtual std::vector<Type> getTypes() final;
    virtual int getLevel() final;
    virtual bool isAlive() final;
    virtual bool attack(Pokemon& var1) final;
    virtual void turn() final;
    virtual void prepareMove() final;
    virtual std::shared_ptr<Move> getPreparedMove() final;
    virtual std::string getName() final;
protected:
    virtual void setMove(int n, std::shared_ptr<Move> var1, ...) final;
    virtual void addMove(std::shared_ptr<Move> var1) final;
    virtual void setType(int n, Type var1, ...) final;
    virtual void addType(Type var1) final;

};
