#include "Writer.h"
std::string Writer::getMessage(Messages var1) {
	switch (var1) {
	case(Messages::poke):
		return "Pokemon";
		break;
	case(Messages::noname):
		return "Unnamed";
		break;
	case(Messages::burn):
		return "is burned";
		break;
	case(Messages::freeze):
		return "is frozen";
		break;
	case(Messages::thawn):
		return "thawns";
		break;
	case(Messages::paralyze):
		return "is paralyzed";
		break;
	case(Messages::poison):
		return "is poisoned";
		break;
	case(Messages::sleep):
		return "is sleeping";
		break;
	case(Messages::faint):
		return "faints.";
		break;
	case(Messages::bothFaint):
		return "Both pokemons faint.";
		break;
	case(Messages::HP):
		return "hit points";
		break;
	case(Messages::ATTACK):
		return "attack";
		break;
	case(Messages::DEFENSE):
		return "defense";
		break;
	case(Messages::SPEED):
		return "speed";
		break;
	case(Messages::SPECIAL_ATTACK):
		return "special attack";
		break;
	case(Messages::SPECIAL_DEFENSE):
		return "special defense";
		break;
	case(Messages::ACCURACY):
		return "accuracy";
		break;
	case(Messages::EVASION):
		return "evasion";
		break;
	case(Messages::minusHP):
		return "loses";
		break;
	case(Messages::plusHP):
		return "restores";
		break;
	case(Messages::minusStat):
		return "decreases";
		break;
	case(Messages::plusStat):
		return "increases";
		break;
	case(Messages::attack):
		return "attacks";
		break;
	case(Messages::struggle):
		return "struggles";
		break;
	case(Messages::noattack):
		return "does nothing";
		break;
	case(Messages::confusion):
		return "hits himself in confusion";
		break;
	case(Messages::noeffect):
		return "isn't affected by";
		break;
	case(Messages::miss):
		return "misses";
		break;
	case(Messages::from):
		return "from the team";
		break;
	case(Messages::enter):
		return "enters the battle";
		break;
	case(Messages::tie):
		return "Both teams are out of Pokemons. It's a tie!";
		break;
	case(Messages::inTeam):
		return "Team";
		break;
	case(Messages::empty):
		return "loses its last Pokemon.";
		break;
	case(Messages::team):
		return "The team";
		break;
	case(Messages::wins):
		return "wins the battle!";
		break;
	case(Messages::critical):
		return "Critical hit!";	
		break;
	}
}
//мб удалю статы из mess
std::string Writer::StatToString(Stat var1) {
	switch (var1) {
	case(Stat::HP):
		return "hit points";
		break;
	case(Stat::ATTACK):
		return "attack";
		break;
	case(Stat::DEFENSE):
		return "defense";
		break;
	case(Stat::SPEED):
		return "speed";
		break;
	case(Stat::SPECIAL_ATTACK):
		return "special attack";
		break;
	case(Stat::SPECIAL_DEFENSE):
		return "special deffense";
		break;
	case(Stat::ACCURACY):
		return "accuracy";
		break;
	case(Stat::EVASION):
		return "evasion";
		break;
	}
}
std::string Writer::TypeToString(Type var1) {
	switch (var1) {
	case(Type::NORMAL):
		return "normal";
		break;
	case(Type::FIRE):
		return "fire";
		break;
	case(Type::WATER):
		return "water";
		break;
	case(Type::ELECTRIC):
		return "electric";
		break;
	case(Type::GRASS):
		return "grass";
		break;
	case(Type::ICE):
		return "ice";
		break;
	case(Type::FIGHTING):
		return "fighting";
		break;
	case(Type::POISON):
		return "poison";
		break;
	case(Type::GROUND):
		return "ground";
		break;
	case(Type::FLYING):
		return "flying";
		break;
	case(Type::PSYCHIC):
		return "psychic";
		break;
	case(Type::BUG):
		return "bug";
		break;
	case(Type::ROCK):
		return "rock";
		break;
	case(Type::GHOST):
		return "ghost";
		break;
	case(Type::DRAGON):
		return "dragon";
		break;
	case(Type::DARK):
		return "dark";
		break;
	case(Type::STEEL):
		return "steel";
		break;
	case(Type::FAIRY):
		return "fairy";
		break;
	}
}