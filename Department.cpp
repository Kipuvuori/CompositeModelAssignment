#include "Department.h"

Department::Department(int id) : Base(id)
{
}

void Department::addProject(Project project)
{
	this->addChild(project);
}

Department::~Department()
{
}
