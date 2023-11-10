class Effect;
#include "Pokemon.h"
#include <iostream>
#include <vector>
#include <stdarg.h>
    Pokemon::Pokemon() {}
    //деструктор
    Pokemon::Pokemon(std::string var1, int var2) {
        this->types.push_back(Type::NONE);
        this->setLevel(var2);
        this->name = var1;
        //move
    }
    void Pokemon::setLevel(int var1) {
        if (var1 < 1)
            var1 = 1;
        if (var1 > 100)
            var1 = 100;
        this->level = var1;
    }
    void Pokemon::setStats(double var1, double var2, double var3, double var4, double var5, double var6) {
        this->base[static_cast<int>(Stat::HP)] = var1;
        this->base[static_cast<int>(Stat::ATTACK)] = var2;
        this->base[static_cast<int>(Stat::DEFENSE)] = var3;
        this->base[static_cast<int>(Stat::SPECIAL_ATTACK)] = var4;
        this->base[static_cast<int>(Stat::SPECIAL_DEFENSE)] = var5;
        this->base[static_cast<int>(Stat::SPEED)] = var6;
    }
        double  Pokemon::getStat(Stat var1) {
        double var6 = this->base[static_cast<int>(var1)];
        double var8 = (double)this->stage.stat(var1);
        if (this->condition.success())
            var8 += (double)this->condition.stat(var1);
        Effect var11;
        for (int i = 0; i < this->effects.size(); i++) {
            var11 = this->effects[i];
            if (var11.success())
                var8 += (double)var11.stat(var1);
        }
        if (var8 > 6)
            var8 = 6;
        if (var8 < -6)
            var8 = -6;
        double var14 = 0.0;
        double var12 = 2.0;
        if ((var1 == Stat::ACCURACY) || (var1 == Stat::EVASION)) {
            var12 = 3.0;
        } else if(var1 == Stat::HP) {
            var14 = (double)this->level + 10.0;
        } else {
            var14 = 5.0;
        }
        if (var1 == Stat::HP) {
            var6 *= 1.0;
        }
        else if(var8 > 0) {
            var6 *= (var12 + var8) / var12;
        }
        else {
            var6 *= var12 / (var12 + var8);
        }
        if ((var1 != Stat::ACCURACY) && (var1 != Stat::EVASION))
            var6 = (var6 * 2.0 + 15.0) * (double)this->level / 100.0;
        var6 += var14;
        return var6;
    }
    bool Pokemon::hasType(Type var1) {
        if (std::find(types.begin(), types.end(), var1) != types.end())
            return true;
        else return false;
    }
    void Pokemon::addEffect(Effect var1) {
        if (var1.status() == Status::NORMAL)
            this->effects.push_back(var1);
        else this->setCondition(var1);
    }
        void Pokemon::setCondition(Effect var1) {
            if ((var1.success()) && (this->condition.status() != var1.status())) {
                this->condition = var1;
                std::string var2 = "";
                switch (var1.status()) {
                case Status::BURN:
                    //mess
                    break;
                case Status::FREEZE:
                    //mess
                    break;
                case Status::PARALYZE:
                    //mess
                    break;
                case Status::POISON:
                    //mess
                    break;
                case Status::SLEEP:
                    //mess
                    break;
                }
                std::cout << this << " " << var2 << std::endl; //хз 
            }

        }
    Status Pokemon::getCondition() { return this->condition.status(); }
    void Pokemon::confuse() {
        this->confusion = (int)(((rand()) / RAND_MAX) * 4.0 + 1.0);
    }
    void Pokemon::restore() {
        this->base[static_cast<int>(Stat::ACCURACY)] = 1.0;
        this->base[static_cast<int>(Stat::EVASION)] = 1.0;
        this->condition.clear();
        this->stage.clear();
        this->effects.clear();
    }
    double Pokemon::getHP() { return this->getStat(Stat::HP) - (double)this->stage.stat(Stat::HP); }
    void Pokemon::setMod(Stat var1, int var2) {
        if (var2 != 0) {
            int var3 = var2 + this->stage.stat(var1);
            std::string var4 = "";
            if (var1 == Stat::HP) {
                //mess
            }
            else {
                if (var3 > 6) 
                    var3 = 6;
                if (var3 < -6) 
                    var3 = -6;
                //mess
            }
            this->stage.stats(var1, var3);
            //mess
        }
    }
    std::vector<Type> Pokemon::getTypes() {
        return this->types; //хз
    }
    int Pokemon::getLevel() {
        return this->level;
    }
    double Pokemon::getAttackChance() {
        double var1 = this->stage.attack();
        var1 *= this->condition.attack();
        Effect var4;
        for (int i = 0; i < this->effects.size(); i++) {
            var4 = this->effects[i];
            var1 *= var4.attack();
        }
        return var1;
    }
    //prepareMove
    bool Pokemon::isAlive() {
        return this->getStat(Stat::HP) > (double)this->stage.stat(Stat::HP);
    }
    //attack
    void Pokemon::turn() {
        this->setMod(Stat::HP, this->condition.stat(Stat::HP));
        if (this->condition.turn()) {
            this->condition.clear();
            //mess
        }
        Effect var2;
        for (int i = 0; i < this->effects.size(); i++) {
            var2 = this->effects[i];
            this->setMod(Stat::HP, var2.stat(Stat::HP));
            if (var2.turn())
                var2.clear();
        }
    }
    void Pokemon::setType(int n, Type var1, ...) {
        this->types.clear();
        va_list factor;
        va_start(factor, var1);
        this->types.push_back(var1);
        for (int i = 0; i < n - 1; i++) {
            this->types.push_back(va_arg(factor, Type));
            if (this->types.size() >= 2)
                break;
        }
        va_end(factor);
    }
    void Pokemon::addType(Type var1) {
        if (this->types.size() < 2 && !this->hasType(var1))
            this->types.push_back(var1);
    }
    //setMove
    //addMove
    //getPreparedMove
    //toString
