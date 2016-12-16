#pragma once
#include "Base.h"
#include "Employee.h"

class Project : public Base
{
public:
	Project(int id, std::string name);
	void addEmployee(Employee employee);
	~Project();
private:
};

