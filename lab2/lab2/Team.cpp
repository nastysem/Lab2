#include "Team.h"
Team::Team(std::string var1) {
    this->name = var1;
}
Team::Team() {

}
void Team::add(std::shared_ptr<Pokemon> var1) {
    this->team.push(var1);
}
std::shared_ptr<Pokemon> Team::next() {
    if ((this->pokemon == NULL || !this->pokemon->isAlive()) && !this->team.empty()) {
        this->pokemon = this->team.front();
        this->team.pop();
        this->pokemon->restore();
        std::cout << this->pokemon->getName() << " " << Writer::getMessage(Messages::from) << " " << this->name << " " << Writer::getMessage(Messages::enter) << std::endl;
    }
    return this->pokemon;
}
bool Team::hasNext() {
    return !this->team.empty() || this->pokemon->isAlive();
}
std::shared_ptr<Pokemon> Team::poke() {
    return this->pokemon;
}
std::string Team::getName() {
    return this->name;
}