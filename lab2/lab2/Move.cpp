#include "Pokemon.h"
#include "Move.h"
#include "PhysicalMove.h"
Move::~Move() {}
Move::Move() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            effects[i][j] = 0;
        }
    }
    this->type = Type::NONE;
    this->accuracy = 0.0;
    this->power = 1.0;
    this->priority = 0;
    this->hits = 1;
}
Move::Move(Type var1, double var2, double var4) {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            effects[i][j] = 0;
        }
    }
    this->type = var1;
    this->accuracy = var4;
    this->power = var2;
    this->priority = 0;
    this->hits = 1;

}
Move::Move(Type var1, double var2, double var4, int var6, int var7) {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            effects[i][j] = 0;
        }
    }
    this->type = var1;
    this->accuracy = var4;
    this->power = var2;
    this->priority = var6;
    this->hits = var7;
}
double Move::effect(Type var1) {
    return 1.0 - (double)effects[static_cast<int>(this->type)][static_cast<int>(var1)] / 2;
}
void Move::setX(int var1, Type var2) {
    effects[static_cast<int>(this->type)][static_cast<int>(var2)] = var1;
}
Type Move::zero(int n, Type var1, ...) {
    va_list factor;
    va_start(factor, var1);
    Type var3 = var1;
    this->setX(2, var3);
    for (int i = 0; i < n - 1; i++) {
        var3 = va_arg(factor, Type);
        this->setX(2, var3);
    }
    va_end(factor);
    return this->type;
}
Type Move::half(int n, Type var1, ...) {
    va_list factor;
    va_start(factor, var1);
    Type var3 = var1;
    this->setX(1, var3);
    for (int i = 0; i < n - 1; i++) {
        var3 = va_arg(factor, Type);
        this->setX(1, var3);
    }
    va_end(factor);
    return this->type;
}
Type Move::doub(int n, Type var1, ...) {
    va_list factor;
    va_start(factor, var1);
    Type var3 = var1;
    this->setX(-2, var3);
    for (int i = 0; i < n - 1; i++) {
        var3 = va_arg(factor, Type);
        this->setX(-2, var3);
    }
    va_end(factor);
    return this->type;
}
void Move::setEffect() {
    switch (this->type) {
    case(Type::NORMAL):
        this->half(2, Type::ROCK, Type::STEEL);
        this->zero(1, Type::GHOST);
        break;
    case(Type::FIRE):
        this->half(4, Type::FIRE, Type::WATER, Type::ROCK, Type::DRAGON);
        this->doub(4, Type::GRASS, Type::ICE, Type::BUG, Type::STEEL);
        break;
    case(Type::WATER):
        this->doub(3, Type::FIRE, Type::GROUND, Type::ROCK);
        this->half(3, Type::WATER, Type::GRASS, Type::DRAGON);
        break;
    case(Type::ELECTRIC):
        this->doub(2, Type::WATER, Type::FLYING);
        this->half(3, Type::ELECTRIC, Type::GRASS, Type::DRAGON);
        this->zero(1, Type::GROUND);
        break;
    case(Type::GRASS):
        this->half(7, Type::FIRE, Type::GRASS, Type::POISON, Type::FLYING, Type::BUG, Type::DRAGON, Type::STEEL);
        this->doub(3, Type::WATER, Type::GROUND, Type::ROCK);
        break;
    case(Type::ICE):
        this->half(4, Type::FIRE, Type::WATER, Type::ICE, Type::STEEL);
        this->doub(4, Type::GRASS, Type::GROUND, Type::FLYING, Type::DRAGON);
        break;
    case(Type::FIGHTING):
        this->doub(5, Type::NORMAL, Type::ICE, Type::ROCK, Type::DARK, Type::STEEL);
        this->half(5, Type::POISON, Type::FLYING, Type::PSYCHIC, Type::BUG, Type::FAIRY);
        this->zero(1, Type::GHOST);
        break;
    case(Type::POISON):
        this->doub(2, Type::GRASS, Type::FAIRY);
        this->half(4, Type::POISON, Type::GROUND, Type::ROCK, Type::GHOST);
        this->zero(1, Type::STEEL);
        break;
    case(Type::GROUND):
        this->doub(5, Type::FIRE, Type::ELECTRIC, Type::POISON, Type::ROCK, Type::STEEL);
        this->half(2, Type::GRASS, Type::BUG);
        this->zero(1, Type::FLYING);
        break;
    case(Type::FLYING):
        this->half(3, Type::ELECTRIC, Type::ROCK, Type::STEEL);
        this->doub(3, Type::GRASS, Type::FIGHTING, Type::BUG);
        break;
    case(Type::PSYCHIC):
        this->doub(2, Type::FIGHTING, Type::POISON);
        this->half(2, Type::PSYCHIC, Type::STEEL);
        this->zero(1, Type::DARK);
        break;
    case(Type::BUG):
        this->half(7, Type::FIRE, Type::FIGHTING, Type::POISON, Type::FLYING, Type::GHOST, Type::STEEL, Type::FAIRY);
        this->doub(3, Type::GRASS, Type::PSYCHIC, Type::DARK);
        break;
    case(Type::ROCK):
        this->doub(4, Type::FIRE, Type::ICE, Type::FLYING, Type::BUG);
        this->half(3, Type::FIGHTING, Type::GROUND, Type::STEEL);
        break;
    case(Type::GHOST):
        this->zero(1, Type::NORMAL);
        this->doub(2, Type::PSYCHIC, Type::GHOST);
        this->half(1, Type::DARK);
        break;
    case(Type::DRAGON):
        this->doub(1, Type::DRAGON);
        this->half(1, Type::STEEL);
        this->zero(1, Type::FAIRY);
        break;
    case(Type::DARK):
        this->half(3, Type::FIGHTING, Type::DARK, Type::FAIRY);
        this->doub(2, Type::PSYCHIC, Type::GHOST);
        break;
    case(Type::STEEL):
        this->half(5, Type::FIRE, Type::WATER, Type::ELECTRIC, Type::STEEL, Type::FAIRY);
        this->doub(2, Type::ICE, Type::ROCK);
        break;
    case(Type::FAIRY):
        this->half(3, Type::FIRE, Type::POISON, Type::STEEL);
        this->doub(3, Type::FIGHTING, Type::DRAGON, Type::DARK);
        break;
    case(Type::NONE):
        break;
    }
}
double Move::getEffect(int n, Type var1, ...) {
    this->setEffect();
    double var2 = 1.0;
    va_list factor;
    va_start(factor, var1);
    Type var3 = var1;
    var2 *= this->effect(var3);
    for (int i = 0; i < n - 1; i++) {
        var3 = va_arg(factor, Type);
        var2 *= this->effect(var3);
    }
    va_end(factor);
    return var2;
}
double Move::getEffectForPokemon(Pokemon& var1) {
    switch (var1.getTypes().size()) {
    case(1):
        return this->getEffect(1, var1.getTypes()[0]);
        break;
    case(2):
        return this->getEffect(2, var1.getTypes()[0], var1.getTypes()[1]);
        break;
    }
}
bool Move::checkAccuracy(Pokemon& var1, Pokemon& var2) {
    return this->accuracy * var1.getStat(Stat::ACCURACY) / var2.getStat(Stat::EVASION) > (double)(rand()) / RAND_MAX;
}
int Move::getPriority() {
    return this->priority;
}
std::string Move::describe() {
    return Writer::getMessage(Messages::attack);
}
void Move::applyOppEffects(Pokemon& var1) {

}
void Move::applySelfEffects(Pokemon& var1) {

}

