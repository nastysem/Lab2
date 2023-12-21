#include "Console.h"
void Console::info() {
	std::cout << "The first pokemon is NidoranF. It's base characteristics are HP - 55, ATTACK - 47, DEFENSE - 52, SPECIAL ATTACK - 40, SPECIAL DEFENSE - 40, SPEED - 41. It performs Confide and Sludge Bomb. Press 1 to choose it." << "\n" << std::endl;
	std::cout << "The second pokemon is Nidorina. It's a heir of NidoranF. It's base characteristics are HP - 70, ATTACK - 62, DEFENSE - 67, SPECIAL ATTACK - 55, SPECIAL DEFENSE - 55, SPEED - 56. It performs Confide, Sludge Bomb and Bite. Press 2 to choose it." << "\n" << std::endl;
	std::cout << "The third pokemon is Nidoqueen. It's a heir of Nidona. It's base characteristics are HP - 90, ATTACK - 92, DEFENSE - 87, SPECIAL ATTACK - 75, SPECIAL DEFENSE - 85, SPEED - 76. It performs Confide, Sludge Bomb, Bite and Shadow Ball. Press 3 to choose it." << "\n" << std::endl;
	std::cout << "The forth pokemon is Tyrogue. It's base characteristics are HP - 35, ATTACK - 35, DEFENSE - 35, SPECIAL ATTACK - 35, SPECIAL DEFENSE - 35, SPEED - 35. It performs Rest, Facade and Double Team. Press 4 to choose it." << std::endl;
	std::cout << "The fifth pokemon is Htmonlee. It's a heir of Tyrogue. It's base characteristics are HP - 50, ATTACK - 120, DEFENSE - 53, SPECIAL ATTACK - 35, SPECIAL DEFENSE - 110, SPEED - 87. It performs Rest, Facade, Double Team and Rock Tomb. Press 5 to choose it." << "\n" << std::endl;
	std::cout << "The sixth pokemon is Throh. It's base characteristics are HP - 120, ATTACK - 100, DEFENSE - 85, SPECIAL ATTACK - 30, SPECIAL DEFENSE - 85, SPEED - 45. It performs Stone Edge, Seismic Toss, Confide and Swagger. Press 6 to choose it." << std::endl;
}
void Console::choose1(int var1) {
	std::cout << "Choose your pokemon's name: ";
	std::cin >> name;
	std::cout << "Choose your pokemon's level: ";
	std::cin >> level;
	switch (var1) {
	case(1):
	{
		NidoranF p(name, level);
		b.addAlly(std::make_shared<NidoranF>(p));
		break;
	}
	case(2): {
		Nidorina p2(name, level);
		b.addAlly(std::make_shared<Nidorina>(p2));
		break;
	}
	case(3): {
		Nidoqueen p3(name, level);
		b.addAlly(std::make_shared<Nidoqueen>(p3));
		break;
	}
	case(4): {
		Tyrogue p4(name, level);
		b.addAlly(std::make_shared<Tyrogue>(p4));
		break;
	}
	case(5): {
		Hitmonlee p5(name, level);
		b.addAlly(std::make_shared<Hitmonlee>(p5));
		break;
	}
	case(6): {
		Throh p6(name, level);
		b.addAlly(std::make_shared<Throh>(p6));
		break;
	}
	default:
		std::cout << "You entered the wrong number!" << std::endl;
		exit(1);
	}
}
void Console::choose2(int var1) {
	std::cout << "Choose your pokemon's name: ";
	std::cin >> name;
	std::cout << "Choose your pokemon's level: ";
	std::cin >> level;
	switch (var1) {
	case(1):
	{
		NidoranF f(name, level);
		b.addFoe(std::make_shared<NidoranF>(f));
		break;
	}
	case(2): {
		Nidorina f2(name, level);
		b.addFoe(std::make_shared<Nidorina>(f2));
		break;
	}
	case(3): {
		Nidoqueen f3(name, level);
		b.addFoe(std::make_shared<Nidoqueen>(f3));
		break;
	}
	case(4): {
		Tyrogue f4(name, level);
		b.addFoe(std::make_shared<Tyrogue>(f4));
		break;
	}
	case(5): {
		Hitmonlee f5(name, level);
		b.addFoe(std::make_shared<Hitmonlee>(f5));
		break;
	}
	case(6): {
		Throh f6(name, level);
		b.addFoe(std::make_shared<Throh>(f6));
		break;
	}
	default:
		std::cout << "You entered the wrong number!" << std::endl;
		exit(1);
	}
}
void Console::game() {
	std::cout << "Welcome to the Pokemon game! Here you have to make the right choice and fight. If you are ready to proceed, press 1." << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "Player 1, now you are ready to choose your fighters. You will have 3 fighters in your team. Press 1 to continue." << std::endl;
		std::cin >> choice;
		if (choice == 1) {
			info();
			std::cout << "Choose your first fighter: ";
			std::cin >> choice;
			choose1(choice);
			std::cout << "Choose your second fighter: ";
			std::cin >> choice;
			choose1(choice);
			std::cout << "Choose your third fighter: ";
			std::cin >> choice;
			choose1(choice);
			std::cout << "Player 2, it's your turn to choose your fighters. You will have 3 fighters in your team. Press 1 to continue." << std::endl;
			std::cin >> choice;
			if (choice == 1) {
				info();
				std::cout << "Choose your first fighter: ";
				std::cin >> choice;
				choose2(choice);
				std::cout << "Choose your second fighter: ";
				std::cin >> choice;
				choose2(choice);
				std::cout << "Choose your third fighter: ";
				std::cin >> choice;
				choose2(choice);
				b.go();
			}
			else {
				std::cout << "OK, try again later.";
			}
		}
		else {
			std::cout << "OK, try again later.";
		}
	}
	else {
		std::cout << "OK, try again later.";
	}
}