#include "Company.h"

int main()
{
	setlocale(LC_ALL, "finnish");
	Project proj = Project(1, "Tärkeä Projekti");
	proj.addEmployee(Employee(1, "Pekka Miettilä"));
	Project proj2 = Project(2, "Hieno Projekti");
	proj2.addEmployee(Employee(2, "Hieno Mies"));
	proj2.addEmployee(Employee(3, "Hieno Nainen"));

	Department dep = Department(1, "Hieno Osasto");
	dep.addProject(proj);
	dep.addProject(proj2);

	Company comp = Company(1, "Paras Firma");
	comp.addDepartment(dep);

	comp.print("");
	system("pause");
}