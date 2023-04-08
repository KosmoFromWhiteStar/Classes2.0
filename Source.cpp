#include <iostream>
#include <cassert>
#include <vector>

class Branch
{
	int count_hous = 0;
	std::vector<std::string> name_holder;

public:

	int getHouse() { return count_hous; }

	//resizing name_holder vector. accommodation elfs on vector
	void accommodation_in(int count_elf)
	{
		if (count_elf == 0) return;
		name_holder.resize(count_elf);
	}
	void setHouse(int val)
	{
		count_hous = val;
	}
	void set_Name_Elf(std::string name, int index)
	{
		name_holder[index] = name;
	}
	std::string* get_Name(int index) { return &name_holder[index]; }
	int get_Count_Elf() { return name_holder.size(); }
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
		this->accommodation_in(in_count);
		if (in_count == this->get_Count_Elf()) std::cout << "Correct elfs";
		for (int i = 0; i < in_count; i++)
		{
			std::cout << "Input name Elf's: " << std::endl;
			std::string name;
			std::cin >> name;
			this->set_Name_Elf(name, i);
		}
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

//get number house
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