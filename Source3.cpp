#include <iostream>

class Employer
{
private:
	std::string name;
public:
	void set_Name_Employers(std::string in_name) { name = in_name; }
};

class TOP_DIR : public Employer
{
public:
	TOP_DIR(std::string in_name)
	{
		this->set_Name_Employers(in_name);
	}
	void authorize()
	{
		//delegate
	}
};


class Manager : public Employer
{

};

class Worker : public Employer
{

};