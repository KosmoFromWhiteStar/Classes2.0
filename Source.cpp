#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>


class Branch
{
	int count_hous = 0;
	std::vector<std::string> name_holder;

public:

	int get_House() { return count_hous; }

	//resizing name_holder vector. accommodation elfs on vector
	void accommodation_in(int count_elf)
	{
		if (count_elf == 0) return;
		name_holder.resize(count_elf);
	}

	// Устанавливаю количество домов на ветку. Которое сооветсвует количеству Эльфов живущих тут.
	void set_House(int val)
	{
		if (val >= 0)
		{
			std::cerr << "Err: to low value" << std::endl;
			return;
		}
		count_hous = val;
		accommodation_in(val);
	}

	//Индекс - номер дома в котором проживает эльф. Имя None значит что тут никто не проживает.
	void set_Name_Elf(std::string name, int index)
	{
		assert(index > 0);
		name_holder[index] = name;
	}
	
};

class Middle_B : public Branch
{
	//Выделяю место под адрес другого класса для "обратной связи"
	class Big_b* br = nullptr;

public:

	Middle_B(class Big_b* in_br, int in_count) : br(in_br)
	{
		assert(in_count >= 0);
		assert(in_br != nullptr);

		this->set_House(in_count);

		if (in_count == this->get_House()) std::cout << "Correct elfs";
		for (int i = 0; i < in_count; i++)
		{
			std::cout << "Input name Elf's: " << std::endl;
			std::string name;
			std::cin >> name;
			this->set_Name_Elf(name, i);
		}
	}
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

	//in_Count - count middle branch, count_elfs count elfs on Branch
	Big_b(int in_Count, int count_elfs) : count_middle_B(in_Count)
	{
		assert(in_Count >= 0);

		//Inizialization middle branch on big branch
		branch = new Middle_B* [in_Count];
		for (int i = 0; i < count_middle_B;++i)
		{
			branch[i] = new Middle_B(this, count_elfs);
		}
		
		//Input Elfs in Big branch
		this->set_House(in_Count);
		if (in_Count == this->get_House()) std::cout << "Correct elfs";
		for (int i = 0; i < in_Count; i++)
		{
			std::cout << "Input name Elf's: " << std::endl;
			std::string name;
			std::cin >> name;
			this->set_Name_Elf(name, i);
		}
	}
};


class Tree
{
private:
	Big_b** big_b = nullptr;
	int count_BB = 0;
public:
	Tree(int in_count, int in_count_Elf) : count_BB(in_count)
	{
		big_b = new Big_b* [in_count];
		for (int i = 0; i < count_BB;++i)
		{
			int count_MB = std::rand() % 3 + 2;
			big_b[i] = new Big_b(count_MB, in_count_Elf);
		}
	}

};


int main()
{
	std::vector <Tree*> trees(5);
	//construction trees
	for (int i = 0; i < trees.size(); i++)
	{
		int count_BB = std::rand() % 5 + 3;
		std::cout << "Tree: " << i << "count BB: " << count_BB << std::endl;
		trees[i] = new Tree(count_BB, 2);
	}




	//destruction trees
	for (int i = 0; i < trees.size(); i++) 
	{
		delete trees[i];
	}
}
