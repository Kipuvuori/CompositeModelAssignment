#include "Department.h"

Department::Department(int id, std::string name) : Base(id, name)
{
	this->_type = "Department";
	this->_childen_json_name = "projects";

}

Department::Department(nlohmann::json base) : Base(base)
{
	this->_type = "Department";
	this->_childen_json_name = "projects";
	this->addChildren(base);
}

void Department::addProject(Project project)
{
	this->addChild(project);
}

void Department::callAddChild(nlohmann::json child)
{
	this->addProject(Project(child));
}


Department::~Department()
{
}
