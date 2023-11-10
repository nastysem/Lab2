#include "Pokemon.h"
#include <iostream>
int main()
{
	//ЛУЧШЕ В МЭЙНЕ СДЕЛАТЬ ОДНУ ТОЧКУ ОТЧЕТА ДЛЯ РАНДОМА

	Pokemon p("мишка", 1);
	p.setStats(1, 3, 5, 6, 7, 7);
	std::cout << p.getLevel() << std::endl;
	p.setType(1, Type::ICE);
	Effect::burn(p);
	
	
}

