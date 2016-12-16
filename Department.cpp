#include "Department.h"

Department::Department(int id, std::string name) : Base(id, name)
{
}

void Department::addProject(Project project)
{
	this->addChild(project);
}

Department::~Department()
{
}
