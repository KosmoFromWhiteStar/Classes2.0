#include <iostream>
#include <cassert>

class Branch
{
	int count_hous = 0;
public:

	int getHouse() { return count_hous; }
	void setHouse(int val)
	{
		count_hous = val;
	}
};

class Middle_B : public Branch
{
	class Big_b* br = nullptr;

public:

	void load_House(int val)
	{
		if (val > 0 && val < 50)
			this->setHouse(val);
		else
		{
			this->setHouse(49);
		}
	}

	Middle_B(class Big_b* in_br, int in_count) : br(in_br)
	{
		assert(in_count >= 0);
		assert(in_br != nullptr);
		this->setHouse(in_count);
	}

	int getNumber();
};

class Big_b : public Branch
{
	int count_middle_B = 0;
	Middle_B** branch = nullptr;

public:

	Middle_B* getBranchAt(int index)
	{
		if (this == nullptr) return nullptr;
		if (index < 0) return nullptr;
		if (index >= this->count_middle_B) return nullptr;
		return this->branch[index];
	}

	int getCount()
	{
		return count_middle_B;
	}

	Big_b(int inCount, int inPassagersMax) : count_middle_B(inCount)
	{
		assert(inCount >= 0);
		branch = new Middle_B * [inCount];
		for (int i = 0; i < count_middle_B;++i)
		{
			branch[i] = new Middle_B(this, inPassagersMax);
		}
	}
};

int Middle_B::getNumber()
{
	for (int i = 0; i < br->getCount(); i++)
	{
		Middle_B* branch = br->getBranchAt(i);
		if (branch == this) return i;
	}
}

int main()
{
	Big_b* tree = new Big_b(2, 20);
	for (int i = 0; i < tree->getCount(); ++i)
	{
		int count_house = 0;
		std::cin >> count_house;
		tree->getBranchAt(i)->setHouse(count_house);
	}

	Middle_B* car3 = tree->getBranchAt(2);
	if (car3 == nullptr) {
		std::cout << "Null";
		return 0;
	}
	std::cout << car3->getNumber() << ": " << car3->getHouse() << std::endl;
	delete tree;
}