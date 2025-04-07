#pragma once
#include <iostream>

#include "Unit.h"


class CarthageInfantry : public Infantry
{
public:
	CarthageInfantry()
	{
		this->citizenship = Citizenship::Carthage;
		this->attack--;
		this->coldWeapon = "spear";
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

class CarthageArcher : public Archer
{
public:
	CarthageArcher()
	{
		this->citizenship = Citizenship::Carthage;
		this->defend++;
		this->bowWeapon = "bow";
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

