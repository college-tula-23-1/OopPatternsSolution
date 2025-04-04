#pragma once
#include <iostream>
#include <string>

enum class Citizenship
{
	Roman,
	Carthage,
	Persian
};

class Unit
{
protected:
	Citizenship citizenship;
	std::string title;
	int attack;
	int defend;

public:
	Unit(Citizenship citizenship) :
		citizenship{ citizenship },
		title{""}, attack{}, defend{}{}

	std::string& Title() { return title; }
	int& Attack() { return attack; }
	int& Defend() { return defend; }

	virtual void Move() = 0;
	virtual void Battle(Unit* enemy) = 0;
};


class RomanUnit : public Unit
{
public:
	RomanUnit() : Unit(Citizenship::Roman)
	{
		this->title = "Roman Unit";
		this->attack = 5;
		this->defend = 3;
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



