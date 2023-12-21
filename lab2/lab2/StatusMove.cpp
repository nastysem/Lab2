#include "StatusMove.h"
#include "Pokemon.h"
StatusMove::~StatusMove() {}
void StatusMove::attack(Pokemon& var1, Pokemon& var2) {
    for (int var3 = 0; var3 < this->hits; var3++) {
        if (this->checkAccuracy(var1, var2)) {
            std::cout << var1.getName() << " " << this->describe() << ". " << std::endl;
            if (this->getEffectForPokemon(var2) > 0.0) {
                this->applyOppEffects(var2);
            }
            else {
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
void StatusMove::applySelfEffects(Pokemon& var1) {

}
void StatusMove::applyOppEffects(Pokemon& var1) {
}