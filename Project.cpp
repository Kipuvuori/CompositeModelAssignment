#include "Project.h"



Project::Project(int id, std::string name) : Base(id, name)
{
	this->_type = "Project";
	this->_childen_json_name = "employees";
}

Project::Project(nlohmann::json base) : Base(base)
{
	this->_type = "Project";
	this->_childen_json_name = "employees";
	this->addChildren(base);
}

void Project::addEmployee(Employee employee)
{
	this->addChild(employee);
}

void Project::callAddChild(nlohmann::json child)
{
	this->addEmployee(Employee(child));
}

Project::~Project()
{
}
