#include "Project.h"



Project::Project(int id, std::string name) : Base(id, name)
{
}

void Project::addEmployee(Employee employee)
{
	this->addChild(employee);
}


Project::~Project()
{
}
