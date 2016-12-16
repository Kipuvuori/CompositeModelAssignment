#include "Project.h"



Project::Project(int id, std::string name) : Base(id, name)
{
	this->_type = "Project";
}

void Project::addEmployee(Employee employee)
{
	this->addChild(employee);
}


Project::~Project()
{
}
