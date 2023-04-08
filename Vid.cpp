#include <iostream>
#include <cassert>

class TrainCar
{
	int passengersMax = 0;
	int passenger = 0;
	
	class Train* train = nullptr;

public:

	void loadPassangers(int val)
	{
		if (this == nullptr)
		{
			std::cerr << "This is null" << std::endl;
			return;
		}
		this->passenger += val;
		if (passenger > passengersMax)
		{
			passenger = passengersMax;
		}
	}

	int getPassanger()
	{
		return passenger;
	}

	//Конструктор понятен
	TrainCar(class Train* inTrain, int inPassengersMax)
		: passengersMax(inPassengersMax), train(inTrain)
	{
		assert(inTrain != nullptr);
		assert(inPassengersMax >= 0);
	}
	int getNumber();
	
};

class Train
{
	int count = 0;
	TrainCar** cars = nullptr;

public:
	TrainCar* getCarAt(int index)
	{
		if (this == nullptr) return nullptr;
		if (index < 0) return nullptr;
		if (index >= this->count) return nullptr;
		return this->cars[index];
	}

	int getCount()
	{
		return count;
	}

	/* Вот это вот что, частично ознакомился со статическими функциями, но не понимаю что и зачем это
	static Train* creatTrain(int inCount, int inPassagersMax)
	{
		Train* train = new Train //{ .count = count, .cars = new Train*[count] };
		train-> count = count;
		train-> cars = new Train*[count];
	}*/

	Train(int inCount, int inPassagersMax) : count(inCount)
	{
		assert(inCount >= 0);
		cars = new TrainCar*[inCount];
		for (int i = 0; i < count;++i)
		{
			cars[i] = new TrainCar(this, inPassagersMax);
		}
	}
};

int TrainCar::getNumber()
{
	for (int i = 0; i < train->getCount(); i++)
	{
		TrainCar* car = train->getCarAt(i);
		if (car == this) return i;
	}
	assert(false);
}

int main()
{
	Train* train = new Train(10, 30);
	for (int i = 0; i < train->getCount(); ++i)
	{
		int passenger = 0;
		std::cin >> passenger;
		train->getCarAt(i)->loadPassangers(passenger);
	}

	TrainCar* car3 = train->getCarAt(2);
	std::cout << car3->getNumber() << ": " << car3->getPassanger() << std::endl;

	delete train;
}