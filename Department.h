#pragma once
#include "Base.h"
#include "Project.h"

class Department : public Base
{
public:
	Department(int id, std::string name);
	void addProject(Project company);
	~Department();
private:
};

