#pragma once
#include "Base.h"
#include "Employee.h"

class Project : public Base
{
public:
	Project(int id, std::string name);
	Project(nlohmann::json base);
	void addEmployee(Employee employee);
	void callAddChild(nlohmann::json child) override;
	~Project();
};

