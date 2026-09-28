#ifndef EMPLOYEES_H
#define EMPLOYEES_H

void employeeManagement(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);

double calculateSalary(
    double basic,
    double housing,
    double transport
);

int getEmployeeCount(void);
double getAverageEmployeeSalary(void);
double getHighestEmployeeSalary(void);
double getLowestEmployeeSalary(void);

#endif