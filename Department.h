#pragma once
#include "Base.h"
#include "Project.h"

class Department : public Base
{
public:
	Department(int id);
	void addProject(Project company);
	~Department();
private:
};

