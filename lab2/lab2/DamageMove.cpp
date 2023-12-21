#include "DamageMove.h"
#include "Pokemon.h"
DamageMove::~DamageMove() {}
double DamageMove::calcBaseDamage(Pokemon& var1, Pokemon& var2) {
    return (0.4 * (double)var1.getLevel() + 2.0) * this->power / 150.0;
}
double DamageMove::calcTypeEffect(Pokemon& var1, Pokemon& var2) {
    return this->getEffectForPokemon(var2);
}
double DamageMove::calcCriticalHit(Pokemon& var1, Pokemon& var2) {
    if (var1.getStat(Stat::SPEED) / 512.0 > (double)(rand()) / RAND_MAX) {
        std::cout << Writer::getMessage(Messages::critical) << std::endl;
        return 2.0;
    }
    else {
        return 1.0;
    }
}
double DamageMove::calcSameTypeAttackBonus(Pokemon& var1, Pokemon& var2) {
    double var5 = 1.0;
    if (this->type != Type::NONE) {
        for (int var3 = 0; var3 < var1.getTypes().size(); var3++) {
            Type var4 = var1.getTypes()[var3];
            if (var4 == this->type)
                var5 *= 1.5;
        }
    }
    return var5;
}
double DamageMove::calcRandomDamage(Pokemon& var1, Pokemon& var2) {
    return ((double)(rand()) / RAND_MAX) + 0.15 + 0.85;
}
void  DamageMove::attack(Pokemon& var1, Pokemon& var2) {
    for (int var3 = 0; var3 < this->hits; var3++) {
        if (this->checkAccuracy(var1, var2)) {
            std::cout << var1.getName() << " " << this->describe() << ". " << std::endl;
            double var4 = this->calcBaseDamage(var1, var2) * this->calcAttDefFactor(var1, var2) + 2.0;
            var4 *= this->calcCriticalHit(var1, var2);
            var4 *= this->calcSameTypeAttackBonus(var1, var2);
            var4 *= this->calcRandomDamage(var1, var2);
            var4 *= this->calcTypeEffect(var1, var2);
            if (var4 == 0) {
                var4 = 1.0;
            }
            var4 = (double)std::round(var4);
            this->applyOppDamage(var2, var4);
            this->applySelfDamage(var1, var4);
            if (this->getEffectForPokemon(var2) > 0.0) {
                this->applyOppEffects(var2);
            }
            else
            {
                std::cout << var2.getName() << " " << Writer::getMessage(Messages::noeffect) << " " << Writer::TypeToString(this->type) << std::endl;
            }
            if (this->getEffectForPokemon(var1) > 0.0) {
                this->applySelfEffects(var1);
            }
            else {
                std::cout << var1.getName() << " " << Writer::getMessage(Messages::miss) << std::endl;
            }
        }
    }
}
void DamageMove::applyOppDamage(Pokemon& var1, double var2) {
    var1.setMod(Stat::HP, (int)std::round(var2));
}
void DamageMove::applySelfDamage(Pokemon& var1, double var2) {

}




