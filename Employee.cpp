#include "Employee.h"



Employee::Employee(int id, std::string name) : Base(id, name)
{
	this->_type = "Employee";
}

Employee::~Employee()
{
}
