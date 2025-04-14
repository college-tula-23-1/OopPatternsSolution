#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class ISensor
{
public:
	virtual double GetTemperature() = 0;
};

class CelciumSensor : public ISensor
{
public:
	CelciumSensor()
	{
		srand(time(nullptr));
	}

	double GetTemperature() override
	{
		return -20 + rand() % 41;
	}
};

class FahrenheitSensor
{
public:
	FahrenheitSensor()
	{
		srand(time(nullptr));
	}

	double GetFahrenheitTemperature()
	{
		return (-20 + rand() % 41) * 9 / 5 + 32;
	}
};

class FahrenheitSensorAdapter : public ISensor
{
	FahrenheitSensor* fahrenheitSensor;
public:
	FahrenheitSensorAdapter(FahrenheitSensor* fahrenheitSensor)
		: fahrenheitSensor{ fahrenheitSensor } {};

	double GetTemperature() override
	{
		return (fahrenheitSensor->GetFahrenheitTemperature() - 32) * 5 / 9;
	}
};


class Client
{

	std::vector<ISensor*> sensors;
public:
	Client()
	{

		for (int i{}; i < 5; i++)
		{
			ISensor* sensor;
			if (rand() % 2)
				sensor = new CelciumSensor();
			else
				sensor = new FahrenheitSensorAdapter(new FahrenheitSensor());

			sensors.push_back(sensor);
		}

	}

	void ShowSensorsData()
	{
		std::for_each(sensors.begin(), sensors.end(),
			[](ISensor* sensor) { std::cout << sensor->GetTemperature() << "\n"; });
	}
	
};

