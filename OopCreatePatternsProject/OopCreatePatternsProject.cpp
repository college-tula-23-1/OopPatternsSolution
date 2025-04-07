#include <iostream>
#include <vector>
#include <map>

#include "Unit.h"
#include "UnitFactory.h"
#include "AbstractFacories.h"

//Unit* UnitFactory(Citizenship citizenship)
//{
//	switch (citizenship)
//	{
//	case Citizenship::Roman:
//		return new RomanUnit();
//		break;
//	case Citizenship::Carthage:
//		return new CarthageUnit();
//		break;
//	default:
//		return nullptr;
//		break;
//	}
//}

class ClientUnitFactory
{
	std::map<Citizenship, UnitFactory*> factories;
public:
	void AddFactory(Citizenship citizenship, UnitFactory* factory)
	{
		factories.insert(std::make_pair(citizenship, factory));
	}

	Unit* CreateUnit(Citizenship citizenship)
	{
		return factories[citizenship]->Create();
	}
};

class ClienArmyFactory
{
	std::map< Citizenship, IUnitFactory*> armyFactories;
public:
	void AddFactory(Citizenship citizenship, IUnitFactory* factory)
	{
		armyFactories.insert(std::make_pair(citizenship, factory));
	}

	std::vector<Unit*> CreateArmy(Citizenship citizenship, int size)
	{
		srand(time(nullptr));

		IUnitFactory* factory = armyFactories[citizenship];
		std::vector<Unit*> army;
		for (int i{}; i < size; i++)
		{
			int type = rand() % 2;
			switch (type)
			{
			case 0:
				army.push_back(factory->CreateInfantry());
				break;
			case 1:
				army.push_back(factory->CreateArcher());
				break;
			default:
				break;
			}

		}
	}
};

int main()
{
	/*Unit* unit = UnitFactory(Citizenship::Roman);
	unit->Move();
	unit = UnitFactory(Citizenship::Carthage);
	unit->Move();*/

	/*ClientUnitFactory clientFactory;
	clientFactory.AddFactory(Citizenship::Roman, new RomanUnitFactory());
	clientFactory.AddFactory(Citizenship::Carthage, new CarthageUnitFactory());
	clientFactory.AddFactory(Citizenship::Persian, new PersianUnitFactory());

	Unit* unit = clientFactory.CreateUnit(Citizenship::Carthage);
	unit->Move();
	unit = clientFactory.CreateUnit(Citizenship::Roman);
	unit->Move();
	unit = clientFactory.CreateUnit(Citizenship::Persian);
	unit->Move();*/
}
