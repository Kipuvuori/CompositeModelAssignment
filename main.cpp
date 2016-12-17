#include "Company.h"
#include "json.hpp"
#include <fstream>
#include <vector>
using json = nlohmann::json;

void pause()
{
	std::cin.ignore();
}

inline bool FileIsUsable(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

bool hasFileExtension(const std::string& name, const std::string& extension)
{
	return (name.substr(name.find_last_of(".") + 1) == extension);
}


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "finnish");
	if (argc > 1 && FileIsUsable(argv[1]) && hasFileExtension(argv[1], "json"))
	{
		std::string filename = argv[1];
		std::ifstream i(filename);
		json j;
		i >> j;
		if (j["companies"].is_array())
		{
			std::vector<json> companies = j["companies"].get<std::vector<json>>();
			for (json company : companies)
			{
				Company comp = Company(company);
				comp.print(0);
			}
		}
	}
	else
	{
		Project proj = Project(1, "Tärkeä Projekti");
		proj.addEmployee(Employee(1, "Pekka Miettilä"));

		Project proj2 = Project(2, "Hieno Projekti");
		proj2.addEmployee(Employee(2, "Hieno Mies"));
		proj2.addEmployee(Employee(3, "Hieno Nainen"));


		Department dep = Department(1, "Hieno Osasto");
		dep.addProject(proj);
		dep.addProject(proj2);


		Company comp = Company(1, "Paras Firma");
		comp.addDepartment(dep);

		comp.print(0);
	}

	pause();
	return 1;
}