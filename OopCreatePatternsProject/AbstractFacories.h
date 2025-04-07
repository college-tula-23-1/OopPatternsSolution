#pragma once
#include "RomanUnits.h"
#include "CarthageUnits.h"

class IUnitFactory
{
public:
	virtual Infantry* CreateInfantry() = 0;
	virtual Archer* CreateArcher() = 0;
};

class RomanFactory : public IUnitFactory
{
public:
	RomanInfantry* CreateInfantry() override
	{
		return new RomanInfantry();
	}

	RomanArcher* CreateArcher() override
	{
		return new RomanArcher();
	}
};

class CarthageFactory : public IUnitFactory
{
public:
	CarthageInfantry* CreateInfantry() override
	{
		return new CarthageInfantry();
	}

	CarthageArcher* CreateArcher() override
	{
		return new CarthageArcher();
	}
};

