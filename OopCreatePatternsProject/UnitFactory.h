#pragma once
#include "Unit.h"

class UnitFactory
{
public:
	virtual Unit* Create() = 0;
};

class RomanUnitFactory : public UnitFactory
{
public:
	RomanUnit* Create() override
	{
		return new RomanUnit();
	}
};

class CarthageUnitFactory : public UnitFactory
{
	CarthageUnit* Create() override
	{
		return new CarthageUnit();
	}
};

class PersianUnitFactory : public UnitFactory
{
	PersianUnit* Create() override
	{
		return new PersianUnit();
	}
};

