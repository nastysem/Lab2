#include "Pokemon.h"
Move::Move() {
	this->type = Type::NONE;
	this->accuracy = 0.0;
	this->power = 1.0;
	this->priority = 0;
	this->hits = 1;
}
Move::Move(Type var1, double var2, double var4) {
	this->type = var1;
	this->accuracy = var4;
	this->power = var2;
	this->priority = 0;
	this->hits = 1;
	
}
Move::Move(Type var1, double var2, double var4, int var6, int var7) {
	this->type = var1;
	this->accuracy = var4;
	this->power = var2;
	this->priority = var6;
	this->hits = var7;
}
bool Move::checkAccuracy(Pokemon var1, Pokemon var2) {
	return this->accuracy * var1.getStat(Stat::ACCURACY) / var2.getStat(Stat::EVASION) > (double)(rand()) / RAND_MAX;
}
int Move::getPriority() {
	return this->priority;
}
//describe
void Move::applyOppEffects(Pokemon p) {

}
void Move::applySelfEffects(Pokemon p) {

}
