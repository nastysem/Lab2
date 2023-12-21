#include "Battle.h" 
Battle::Battle() {
    this->allies = std::make_shared<Team>("first");
    this->foes = std::make_shared<Team>("second");
}
void Battle::addAlly(std::shared_ptr<Pokemon>(var1)) {
    this->allies->add(var1);
}
void Battle::addFoe(std::shared_ptr<Pokemon>(var1)) {
    this->foes->add(var1);
}
bool Battle::checkFirst(std::shared_ptr<Pokemon>(var1), std::shared_ptr<Pokemon>(var2)) {
    if (var1->getPreparedMove()->getPriority() == var2->getPreparedMove()->getPriority()) {
        if (var1->getStat(Stat::SPEED) == var2->getStat(Stat::SPEED)) {
            return (double)(rand()) / RAND_MAX >= 0.5;
        }
        else {
            return var1->getStat(Stat::SPEED) > var2->getStat(Stat::SPEED);
        }
    }
    else {
        return var1->getPreparedMove()->getPriority() > var2->getPreparedMove()->getPriority();
    }
}
void Battle::go() {
    do {
        this->allies->next();
        this->foes->next();
        do {
            this->allies->poke()->prepareMove();
            this->foes->poke()->prepareMove();
            std::shared_ptr<Pokemon> var1 = this->checkFirst(this->allies->poke(), this->foes->poke()) ? this->allies->poke() : this->foes->poke();
            std::shared_ptr<Pokemon> var2 = this->checkFirst(this->allies->poke(), this->foes->poke()) ? this->foes->poke() : this->allies->poke();
            if (var1->attack(*var2) || var2->attack(*var1)) {
                break;
            }
            this->allies->poke()->turn();

            if (!this->allies->poke()->isAlive()) {
                break;
            }
            this->foes->poke()->turn();
        } while (this->foes->poke()->isAlive());
    } while (this->allies->hasNext() && this->foes->hasNext());
    if (!this->allies->hasNext() && !this->foes->hasNext()) {
        std::cout << Writer::getMessage(Messages::tie);
    }
    else {
        std::string var3 = (this->allies->hasNext() ? this->allies : this->foes)->getName();
        std::string var4 = (this->foes->hasNext() ? this->allies : this->foes)->getName();
        std::cout << Writer::getMessage(Messages::inTeam) << " " << var4 << " " << Writer::getMessage(Messages::empty) << std::endl;
        std::cout << Writer::getMessage(Messages::team) << " " << var3 << " " << Writer::getMessage(Messages::wins) << std::endl;
    }
}