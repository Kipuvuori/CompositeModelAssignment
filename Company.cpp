#include "Company.h"



Company::Company(int id, std::string name) : Base(id, name)
{
	this->_type = "Company";
}

void Company::addDepartment(Department department)
{
	this->addChild(department);
}


Company::~Company()
{
}
