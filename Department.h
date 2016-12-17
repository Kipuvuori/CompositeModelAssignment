#pragma once
#include "Base.h"
#include "Project.h"

class Department : public Base
{
public:
	Department(int id, std::string name);
	Department(nlohmann::json base);
	void addProject(Project company);
	void callAddChild(nlohmann::json child) override;
	~Department();
};

