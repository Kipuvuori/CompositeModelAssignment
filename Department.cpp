#include "Department.h"

Department::Department(int id, std::string name) : Base(id, name)
{
	this->_type = "Department";
}

void Department::addProject(Project project)
{
	this->addChild(project);
}

Department::~Department()
{
}
