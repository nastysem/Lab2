#include "Move.h"
#pragma once
class NoMove : public Move {
public:
	virtual ~NoMove();
	using Move::Move;
	static NoMove getNoMove();
	void attack(Pokemon& var1, Pokemon& var2) override;
protected:
	std::string describe() override;
};