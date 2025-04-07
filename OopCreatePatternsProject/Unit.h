#pragma once
#include <iostream>
#include <string>

enum class Citizenship
{
	Roman,
	Carthage,
	Persian
};

std::string CitizenshipStr[3] = { "Roman", "Carthage", "Persian" };

enum class UnitType
{
	Infantry,
	Archer,
	Horseman
};

std::string UnitTypeStr[3] = { "Infantry", "Archer", "Horseman" };

class Unit
{
protected:
	Citizenship citizenship;
	UnitType type;
	std::string title;
	int attack;
	int defend;

public:
	Unit() :
		citizenship{}, type{},
		title{""}, attack{}, defend{}{}

	Citizenship& Citizenship() { return citizenship; }
	UnitType& Type() { return type; }

	std::string& Title() { return title; }
	int& Attack() { return attack; }
	int& Defend() { return defend; }

	virtual void Move() = 0;
	virtual void Battle(Unit* enemy) = 0;
};

class Infantry : public Unit
{
protected:
	std::string coldWeapon;
public:
	Infantry()
	{
		this->type = UnitType::Infantry;
		this->attack = 4;
		this->defend = 4;
	}

	std::string& ColdWeapon() { return coldWeapon; }
};

class Archer : public Unit
{
protected:
	std::string bowWeapon;
public:
	Archer()
	{
		this->type = UnitType::Infantry;
		this->attack = 6;
		this->defend = 3;
	}

	std::string& BowWeapon() { return bowWeapon; }
};


/*
class RomanUnit : public Unit
{
public:
	RomanUnit() : Unit(Citizenship::Roman)
	{
		this->title = "Roman Unit";
	}

	void Move() override
	{
		std::cout << this->title << " Move\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << "Battle result:\n"
			<< "attack: " << this->attack - enemy->Attack() << "\n"
			<< "defend: " << this->defend - enemy->Defend() << "\n";
	}

};

class CarthageUnit : public Unit
{
public:
	CarthageUnit() : Unit(Citizenship::Carthage)
	{
		this->title = "Carthage Unit";
		this->attack = 4;
		this->defend = 4;
	}

	void Move() override
	{
		std::cout << this->title << " Move\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << "Battle result:\n"
			<< "attack: " << this->attack - enemy->Attack() << "\n"
			<< "defend: " << this->defend - enemy->Defend() << "\n";
	}

};

class PersianUnit : public Unit
{
public:
	PersianUnit() : Unit(Citizenship::Persian)
	{
		this->title = "Persian Unit";
		this->attack = 6;
		this->defend = 2;
	}

	void Move() override
	{
		std::cout << this->title << " Move\n";
	}

	void Battle(Unit* enemy) override
	{
		std::cout << "Battle result:\n"
			<< "attack: " << this->attack - enemy->Attack() << "\n"
			<< "defend: " << this->defend - enemy->Defend() << "\n";
	}

};
*/


