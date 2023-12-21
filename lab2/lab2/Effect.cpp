#include "Pokemon.h"
#include <iostream>
Effect::Effect() {
    this->conditions = Status::NORMAL;
    for (int i = 0; i < 8; i++) {
        this->mods[i] = 0;
    }
    this->turns = 0;
    this->effectChance = 1.0;
    this->attackChance = 1.0;
}
Effect::~Effect() { }
Effect Effect::setTurns(int var1) {
    this->turns = var1;
    return *this;
}
Effect Effect::chance(double var1) {
    this->effectChance = var1;
    return *this;
}
Effect Effect::attacks(double var1) {
    this->attackChance = var1;
    return *this;
}
double Effect::attack() { return this->attackChance; }
Effect Effect::condition(Status var1) {
    this->conditions = var1;
    return *this;
}
void Effect::clear() {
    for (int i = 0; i < 8; i++) {
        this->mods[i] = 0;
    }
    this->turns = 0;
    this->attackChance = 1.0;
    this->effectChance = 1.0;
    this->conditions = Status::NORMAL;
}
Status Effect::status() {
    return this->conditions;
}
int Effect::stat(Stat var1) {
    return this->mods[static_cast<int>(var1)];
}
Effect Effect::stats(Stat var1, int var2) {
    if (var1 != Stat::HP) {
        if (var2 > 6)
            var2 = 6;
        if (var2 < -6)
            var2 = -6;
    }
    this->mods[static_cast<int>(var1)] = var2;
    return *this;
}
bool Effect::success() {
    return  this->effectChance > (double)(rand()) / RAND_MAX;
}
bool Effect::immediate() {
    return this->turns == 0;
}
bool Effect::turn() {
    return --this->turns == 0;
}
void Effect::burn(Pokemon& p) {
    if (!p.hasType(Type::FIRE)) {
        Effect var1;
        var1 = var1.condition(Status::BURN).setTurns(-1);
        var1.stats(Stat::ATTACK, -2).stats(Stat::HP, (int)p.getStat(Stat::HP) / 16);
        p.setCondition(var1);
    }
}
void Effect::paralyze(Pokemon& p) {
    if (!p.hasType(Type::ELECTRIC)) {
        Effect var1;
        var1 = var1.condition(Status::PARALYZE).attacks(0.75).setTurns(-1);
        var1.stats(Stat::SPEED, -2);
        p.setCondition(var1);
    }
}
void Effect::freeze(Pokemon& p) {
    if (!p.hasType(Type::ICE)) {
        Effect var1;
        var1 = var1.condition(Status::FREEZE).attacks(0.0).setTurns(-1);
        p.setCondition(var1);
    }
}
void Effect::poison(Pokemon& p) {
    if (!p.hasType(Type::POISON) && !p.hasType(Type::STEEL)) {
        Effect var1;
        var1 = var1.condition(Status::POISON).setTurns(-1);
        var1.stats(Stat::HP, (int)p.getStat(Stat::HP) / 8);
        p.setCondition(var1);
    }
}
void Effect::sleep(Pokemon& p) {
    Effect var1;
    var1 = var1.condition(Status::SLEEP).attacks(0.0).setTurns((int)(((double)(rand()) / RAND_MAX) * 3.0 + 1.0));
    p.setCondition(var1);
}
void Effect::flinch(Pokemon& p) {
    Effect var1;
    var1 = var1.attacks(0.0).setTurns(1);
    p.setCondition(var1);
}
void Effect::confuse(Pokemon& p) {
    p.confuse();
}