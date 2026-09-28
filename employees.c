#include <stdio.h>
#include "employees.h"

#define MAX_EMPLOYEES 50

int employeeIDs[MAX_EMPLOYEES];

char employeeNames[MAX_EMPLOYEES][50];
char employeeDepartments[MAX_EMPLOYEES][50];

double basicSalaries[MAX_EMPLOYEES];
double housingAllowances[MAX_EMPLOYEES];
double transportAllowances[MAX_EMPLOYEES];

int employeeCount = 0;


void employeeManagement(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("EMPLOYEE MANAGEMENT\n");
        printf("========================================\n");

        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Return to Main Menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 4);
}


void addEmployee(void)
{
    int newID;
    int i;

    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &newID);

    if (newID <= 0)
    {
        printf("\nEmployee ID must be greater than 0.\n");
        return;
    }

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == newID)
        {
            printf("\nEmployee ID already exists.\n");
            return;
        }
    }

    employeeIDs[employeeCount] = newID;

    printf("Enter Employee Name: ");
    scanf(" %49[^\n]", employeeNames[employeeCount]);

    printf("Enter Department: ");
    scanf(" %49[^\n]", employeeDepartments[employeeCount]);

    printf("Enter Basic Salary: ");
    scanf("%lf", &basicSalaries[employeeCount]);

    printf("Enter Housing Allowance: ");
    scanf("%lf", &housingAllowances[employeeCount]);

    printf("Enter Transport Allowance: ");
    scanf("%lf", &transportAllowances[employeeCount]);

    if (basicSalaries[employeeCount] < 0 ||
        housingAllowances[employeeCount] < 0 ||
        transportAllowances[employeeCount] < 0)
    {
        printf("\nSalary and allowances cannot be negative.\n");
        return;
    }

    employeeCount++;

    printf("\nEmployee added successfully.\n");
}


double calculateSalary(
    double basic,
    double housing,
    double transport
)
{
    return basic + housing + transport;
}


void displayEmployees(void)
{
    int i;
    double grossSalary;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added.\n");
        return;
    }

    printf("\n========================================\n");
    printf("EMPLOYEE LIST\n");
    printf("========================================\n");

    for (i = 0; i < employeeCount; i++)
    {
        grossSalary = calculateSalary(
            basicSalaries[i],
            housingAllowances[i],
            transportAllowances[i]
        );

        printf("\nEmployee %d\n", i + 1);
        printf("----------------------------------------\n");

        printf("Employee ID       : %d\n", employeeIDs[i]);
        printf("Name              : %s\n", employeeNames[i]);
        printf("Department        : %s\n", employeeDepartments[i]);
        printf("Basic Salary      : N$%.2f\n", basicSalaries[i]);
        printf("Housing Allowance : N$%.2f\n", housingAllowances[i]);
        printf("Transport Allow.  : N$%.2f\n", transportAllowances[i]);
        printf("Gross Salary      : N$%.2f\n", grossSalary);
    }
}


void searchEmployee(void)
{
    int searchID;
    int i;
    double grossSalary;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added.\n");
        return;
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &searchID);

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == searchID)
        {
            grossSalary = calculateSalary(
                basicSalaries[i],
                housingAllowances[i],
                transportAllowances[i]
            );

            printf("\nEMPLOYEE FOUND\n");
            printf("----------------------------------------\n");

            printf("Employee ID  : %d\n", employeeIDs[i]);
            printf("Name         : %s\n", employeeNames[i]);
            printf("Department   : %s\n", employeeDepartments[i]);
            printf("Gross Salary : N$%.2f\n", grossSalary);

            return;
        }
    }

    printf("\nEmployee not found.\n");
}
int getEmployeeCount(void)
{
    return employeeCount;
}


double getAverageEmployeeSalary(void)
{
    int i;
    double total = 0.0;

    if (employeeCount == 0)
    {
        return 0.0;
    }

    for (i = 0; i < employeeCount; i++)
    {
        total += calculateSalary(
            basicSalaries[i],
            housingAllowances[i],
            transportAllowances[i]
        );
    }

    return total / employeeCount;
}


double getHighestEmployeeSalary(void)
{
    int i;
    double highest;

    if (employeeCount == 0)
    {
        return 0.0;
    }

    highest = calculateSalary(
        basicSalaries[0],
        housingAllowances[0],
        transportAllowances[0]
    );

    for (i = 1; i < employeeCount; i++)
    {
        double salary = calculateSalary(
            basicSalaries[i],
            housingAllowances[i],
            transportAllowances[i]
        );

        if (salary > highest)
        {
            highest = salary;
        }
    }

    return highest;
}


double getLowestEmployeeSalary(void)
{
    int i;
    double lowest;

    if (employeeCount == 0)
    {
        return 0.0;
    }

    lowest = calculateSalary(
        basicSalaries[0],
        housingAllowances[0],
        transportAllowances[0]
    );

    for (i = 1; i < employeeCount; i++)
    {
        double salary = calculateSalary(
            basicSalaries[i],
            housingAllowances[i],
            transportAllowances[i]
        );

        if (salary < lowest)
        {
            lowest = salary;
        }
    }

    return lowest;
}