#include <iostream>
#include <string>
#include <vector>

static short int numeric;

class Employer
{
private:
	std::string name = "";
	bool in_work = false;
public:
	void set_Name_Employers(std::string in_name) { name = in_name; }
	std::string* get_Name()
	{
		return &name;
	}
};


class Manager : public Employer
{
	int indentificator = 0;
public:
	Manager(int in_num) : indentificator(in_num)
	{
		std::cout << "Input name manager\n";
		std::string in_name = "";
		std::cin >> in_name;
		this->set_Name_Employers(in_name);
		if (in_num < 0)
		{
			indentificator += numeric;
		}
	}
	int managers(int seed)
	{
		std::cout << *this->get_Name() << " take a work\n";
		seed += indentificator;
		std::srand(seed);
		return std::rand();
	}
};
/// <summary>
/// Workers do some <see cref="Worker"/>
/// </summary>
class Worker : public Employer
{
	bool in_work = false;
public:
	char work(int seed)
	{
		std::srand(seed + std::rand());
		int result = std::rand() % 3;
		this->in_work = true;
		std::cout << *this->get_Name() << " take a work\n";
		if (result == 1) return 'A';
		if (result == 2) return 'B';
		if (result == 0) return 'C';
	}
	char status_work() const
	{
		return (in_work ? 'Y' : 'N');
	}
};

class Team
{
	Manager* manager = nullptr;
	Worker** empl = nullptr;
	int in_Work_empl = 0;
	int count_workers = 0;
	int task = 0;
	int empl_free_index = 0;

public:
	Team(int in_task, int in_count_workers, int in_command) : task(in_task),
		count_workers(in_count_workers)
	{
		manager = new Manager(numeric);
		numeric++;

		empl = new Worker * [in_count_workers];

		for (int i = 0; i < in_count_workers; i++)
		{
			empl[i] = new Worker();
			empl[i]->set_Name_Employers("Worker #" + std::to_string(i));
		}
	}

	std::string get_work(int in_task = 0)
	{
		if (in_task != 0) task = in_task;//Êîñòûëü äëÿ âûäà÷è ïîâòîðîé çàäà÷è äëÿ ëîäûðåé.
		int manager_work = manager->managers(task);
		std::string result = std::to_string(manager_work);
		int task_Count = (rand() % count_workers);
		for (int e = 0; e < task_Count; e++)
		{
			if (e + empl_free_index >= count_workers) break;
			if (empl[e + empl_free_index]->status_work() == 'N')
			{
				result += empl[e]->work(manager_work);
				in_Work_empl++;
			}
		}
		empl_free_index = in_Work_empl;
		return result;
	}
	int get_count_Workers() { return count_workers; }
	int get_count_busy_workers() { return in_Work_empl; }
	Worker* get_Worker(int index) {
		if (index > count_workers || index < 0)
		{
			std::cout << "Invalid index\n";
			return nullptr;
		}
		return empl[index];
	}
	~Team()
	{
		delete manager;
		for (int i = 0; i < count_workers; i++)
		{
			delete empl[i];
		}
	}
};

int main(int argc, char* argv[])
{
	//creat Teams
	numeric = 0;
	std::cout << "Count teams: \n";
	int count_team = 0;
	std::cin >> count_team;
	Team** team = new Team * [count_team];

	std::cout << "Count workers: \n";
	int count_workers = 0;
	std::cin >> count_workers;

	//take a command
	std::cout << "Input command: \n";
	int task = 0;
	std::cin >> task;

	// init Teams

	for (int i = 0; i < count_team; i++)
	{
		if (task == 0) break;
		team[i] = new Team(task, count_workers, i);
	}
	bool full_work = false;
	int new_task = 0;
	std::vector <std::string> task_s(5);
	do {

		task_s.push_back(team[0]->get_work(new_task));
		full_work = team[0]->get_count_Workers() == team[0]->get_count_busy_workers();
		if (!full_work)
		{
			std::cout << "new task " << std::endl;
			std::cin >> new_task;
		}
	} while (!full_work);
	for (int i = task_s.size()-1; i > 0 ; i--)
	{
		if (task_s[i].empty()) break;
		std::cout << "Work #" << task_s.size()-i << " " << task_s[i] << std::endl;
	}

	return 0;
}
