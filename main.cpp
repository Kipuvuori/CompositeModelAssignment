#include "Company.h"

int main()
{
	Employee emp = Employee(1);
	Project proj = Project(2);
	Department dep = Department(3);
	Company comp = Company(4);
	proj.addEmployee(emp);
	dep.addProject(proj);
	comp.addDepartment(dep);
	comp.print("");
	system("pause");
}