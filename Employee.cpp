#include "Employee.h"



Employee::Employee(int id, std::string name) : Base(id, name)
{
	this->_type = "Employee";
	this->_childen_json_name = "";
}

Employee::Employee(nlohmann::json base) : Base(base)
{
	this->_type = "Employee";
	this->_childen_json_name = "";
	this->addChildren(base);
}

Employee::~Employee()
{
}
