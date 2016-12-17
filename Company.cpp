#include "Company.h"



Company::Company(int id, std::string name) : Base(id, name)
{
	this->_type = "Company";
	this->_childen_json_name = "departments";

}

Company::Company(nlohmann::json base) : Base(base)
{
	this->_type = "Company";
	this->_childen_json_name = "departments";
	this->addChildren(base);
}

void Company::addDepartment(Department department)
{
	this->addChild(department);
}

void Company::callAddChild(nlohmann::json child)
{
	this->addDepartment(Department(child));
}

Company::~Company()
{
}
