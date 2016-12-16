#include "Company.h"



Company::Company(int id) : Base(id)
{
}

void Company::addDepartment(Department department)
{
	this->addChild(department);
}


Company::~Company()
{
}
