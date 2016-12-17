#pragma once
#include "Base.h"
#include "Department.h"

class Company : public Base
{
public:
	Company(int id, std::string name);
	Company(nlohmann::json base);
	void addDepartment(Department department);
	void callAddChild(nlohmann::json child) override;
	~Company();
};

