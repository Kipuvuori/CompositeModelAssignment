#pragma once
#include "Base.h"

class Employee : public Base
{
public:
	Employee(int id, std::string name);
	~Employee();
};

