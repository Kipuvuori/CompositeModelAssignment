#include "Project.h"



Project::Project(int id) : Base(id)
{
}

void Project::addEmployee(Employee employee)
{
	this->addChild(employee);
}


Project::~Project()
{
}
