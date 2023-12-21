#include "Messages.cpp"
#include "Stat.cpp"
#include "Type.cpp"
#include <iostream>
#pragma once
class Writer {
public:
	std::string n;
	static std::string getMessage(Messages var1);
	static std::string StatToString(Stat var1);
	static std::string TypeToString(Type var1);
};
