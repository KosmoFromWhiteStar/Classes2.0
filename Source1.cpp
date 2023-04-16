#include <iostream>
#include <vector>

class Branch
{
private:
	//Index home = index for names in that vector
	std::vector <std::string> names;
public:

	//Get Name 
	std::string* get_Name(int index)
	{
		if (names.size() < 1 || names.size() < index || index < 0) return nullptr;
		return &names[index];
	}

	//accommondation in Elfs
	void set_House(int val)
	{
		if (val <= 0) return;
		names.resize(val);
		for (int i = 0; i < val; i++)
		{
			std::cout << "Input name: " << std::endl;
			std::cin >> names[i];
		}
	}
};

class Mid_Br : Branch
{
public:
	Mid_Br(int in_count)
	{
		this->set_House(in_count);
	}
};

class Big_Br : Branch 
{
	Mid_Br* mid_br = nullptr;

public:

	Big_Br(int in_count)
	{
		//inic bigB
		this->set_House(in_count);
		for(int i = 0; i < ; i++)
		mid_br = new Mid_Br(in_count);

	}

};