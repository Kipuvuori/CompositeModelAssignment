#pragma once
#include "Base.h"
#include "Department.h"

class Company : public Base
{
public:
	Company(int id, std::string name);
	void addDepartment(Department department);
	~Company();
private:
};

