#pragma once
#include "Base.h"
#include "Employee.h"

class Project : public Base
{
public:
	Project(int id);
	void addEmployee(Employee employee);
	~Project();
private:
};

