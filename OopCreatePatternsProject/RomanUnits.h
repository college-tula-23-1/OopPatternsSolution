#pragma once
#include <iostream>

#include "Unit.h"


class RomanInfantry : public Infantry
{
public:
	RomanInfantry()
	{
		this->citizenship = Citizenship::Roman;
		this->attack++;
		this->coldWeapon = "gladius";
	}

	void Move() override
	{
		std::cout << CitizenshipStr[(int)citizenship] << " "
			<< UnitTypeStr[(int)type] << " moved\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << "Battle result:\n"
			<< CitizenshipStr[(int)citizenship] << " " << UnitTypeStr[(int)type] 
			<< " vs " << CitizenshipStr[(int)(enemy->Citizenship())] << " " << UnitTypeStr[(int)enemy->Type()] << "\n"
			<< "attack: " << this->attack - enemy->Attack() << "\n"
			<< "defend: " << this->defend - enemy->Defend() << "\n";
	}
};

class RomanArcher : public Archer
{
public:
	RomanArcher()
	{
		this->citizenship = Citizenship::Roman;
		this->defend++;
		this->bowWeapon = "sagittarii";
	}

	void Move() override
	{
		std::cout << CitizenshipStr[(int)citizenship] << " "
			<< UnitTypeStr[(int)type] << " moved\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << "Battle result:\n"
			<< CitizenshipStr[(int)citizenship] << " " << UnitTypeStr[(int)type]
			<< " vs " << CitizenshipStr[(int)(enemy->Citizenship())] << " " << UnitTypeStr[(int)enemy->Type()] << "\n"
			<< "attack: " << this->attack - enemy->Attack() << "\n"
			<< "defend: " << this->defend - enemy->Defend() << "\n";
	}
};

