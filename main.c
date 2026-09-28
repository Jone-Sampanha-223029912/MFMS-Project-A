#include <stdio.h>

#define MAX_EMPLOYEES 50

/* Employee data */
int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][50];
char departments[MAX_EMPLOYEES][50];

double basicSalaries[MAX_EMPLOYEES];
double housingAllowances[MAX_EMPLOYEES];
double transportAllowances[MAX_EMPLOYEES];

int employeeCount = 0;

/* Function declarations */
void displayMainMenu(void);
void employeeManagement(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
double calculateSalary(double basic, double housing, double transport);

int main()
{
    int choice;

    do
    {
        displayMainMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                employeeManagement();
                break;

            case 2:
                printf("\nBudget Management will be added in Part 4.\n");
                break;

            case 3:
                printf("\nSupplier Management will be added later.\n");
                break;

            case 4:
                printf("\nAsset Management will be added later.\n");
                break;

            case 5:
                printf("\nReports will be added later.\n");
                break;

            case 6:
                printf("\nExiting system. Goodbye.\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}


void displayMainMenu(void)
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}


void employeeManagement(void)
{
    int choice;

    do
    {
        printf("\n========== EMPLOYEE MANAGEMENT ==========\n");
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
    int i;
    int newID;

    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\nEnter Employee ID: ");
    scanf("%d", &newID);

    if (newID <= 0)
    {
        printf("Employee ID must be greater than 0.\n");
        return;
    }

    /* Check for duplicate ID */
    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == newID)
        {
            printf("Employee ID already exists.\n");
            return;
        }
    }

    employeeIDs[employeeCount] = newID;

    printf("Enter Employee Name: ");
    scanf(" %49[^\n]", employeeNames[employeeCount]);

    printf("Enter Department: ");
    scanf(" %49[^\n]", departments[employeeCount]);

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


double calculateSalary(double basic, double housing, double transport)
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

    printf("\n================ EMPLOYEE LIST ================\n");

    for (i = 0; i < employeeCount; i++)
    {
        grossSalary = calculateSalary(
            basicSalaries[i],
            housingAllowances[i],
            transportAllowances[i]
        );

        printf("\nEmployee %d\n", i + 1);
        printf("----------------------------------------\n");
        printf("ID                : %d\n", employeeIDs[i]);
        printf("Name              : %s\n", employeeNames[i]);
        printf("Department        : %s\n", departments[i]);
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

            printf("\nEmployee Found\n");
            printf("----------------------------------------\n");
            printf("ID           : %d\n", employeeIDs[i]);
            printf("Name         : %s\n", employeeNames[i]);
            printf("Department   : %s\n", departments[i]);
            printf("Gross Salary : N$%.2f\n", grossSalary);

            return;
        }
    }

    printf("\nEmployee not found.\n");
}