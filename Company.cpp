#include "Company.h"



Company::Company(int id, std::string name) : Base(id, name)
{
}

void Company::addDepartment(Department department)
{
	this->addChild(department);
}


Company::~Company()
{
}
