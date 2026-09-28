#include <stdio.h>

/* =========================================
   CONSTANTS
   ========================================= */

#define MAX_EMPLOYEES 50
#define MAX_DEPARTMENTS 10


/* =========================================
   EMPLOYEE DATA
   ========================================= */

int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][50];
char employeeDepartments[MAX_EMPLOYEES][50];

double basicSalaries[MAX_EMPLOYEES];
double housingAllowances[MAX_EMPLOYEES];
double transportAllowances[MAX_EMPLOYEES];

int employeeCount = 0;


/* =========================================
   BUDGET DATA
   ========================================= */

char budgetDepartments[MAX_DEPARTMENTS][50];
double allocatedBudgets[MAX_DEPARTMENTS];
double expenditures[MAX_DEPARTMENTS];

int budgetCount = 0;


/* =========================================
   FUNCTION DECLARATIONS
   ========================================= */

void displayMainMenu(void);

/* Employee functions */
void employeeManagement(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
double calculateSalary(double basic, double housing, double transport);

/* Budget functions */
void budgetManagement(void);
void addDepartmentBudget(void);
void displayBudgets(void);


/* =========================================
   MAIN FUNCTION
   ========================================= */

int main()
{
    char municipality[50];
    char mayor[50];
    int population;

    int choice;


    /* =====================================
       PART 1 - BASIC MFMS SETUP
       ===================================== */

    printf("========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    printf("Enter Municipality Name: ");
    scanf(" %49[^\n]", municipality);

    printf("Enter Mayor Name: ");
    scanf(" %49[^\n]", mayor);

    printf("Enter Population: ");
    scanf("%d", &population);


    printf("\n========================================\n");
    printf("MUNICIPALITY INFORMATION\n");
    printf("========================================\n");

    printf("Municipality : %s\n", municipality);
    printf("Mayor        : %s\n", mayor);
    printf("Population   : %d\n", population);


    /* =====================================
       PART 2 - MAIN MENU
       ===================================== */

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
                budgetManagement();
                break;

            case 3:
                printf("\nSupplier Management will be added in Part 5.\n");
                break;

            case 4:
                printf("\nAsset Management will be added later.\n");
                break;

            case 5:
                printf("\nReports will be added later.\n");
                break;

            case 6:
                printf("\nExiting Municipal Financial Management System.\n");
                printf("Goodbye.\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 6.\n");
        }

    } while (choice != 6);


    return 0;
}


/* =========================================
   DISPLAY MAIN MENU
   ========================================= */

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


/* =========================================
   PART 3 - EMPLOYEE MANAGEMENT
   ========================================= */

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
                printf("\nInvalid choice. Please select 1 to 4.\n");
        }

    } while (choice != 4);
}


/* =========================================
   ADD EMPLOYEE
   ========================================= */

void addEmployee(void)
{
    int i;
    int newID;


    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }


    printf("\n========================================\n");
    printf("ADD EMPLOYEE\n");
    printf("========================================\n");


    printf("Enter Employee ID: ");
    scanf("%d", &newID);


    if (newID <= 0)
    {
        printf("\nEmployee ID must be greater than 0.\n");
        return;
    }


    /* Check for duplicate Employee ID */

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


    /* Validate financial values */

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


/* =========================================
   CALCULATE EMPLOYEE SALARY
   ========================================= */

double calculateSalary(double basic, double housing, double transport)
{
    return basic + housing + transport;
}


/* =========================================
   DISPLAY EMPLOYEES
   ========================================= */

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


/* =========================================
   SEARCH EMPLOYEE
   ========================================= */

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


            printf("\n========================================\n");
            printf("EMPLOYEE FOUND\n");
            printf("========================================\n");

            printf("Employee ID  : %d\n", employeeIDs[i]);
            printf("Name         : %s\n", employeeNames[i]);
            printf("Department   : %s\n", employeeDepartments[i]);
            printf("Gross Salary : N$%.2f\n", grossSalary);

            return;
        }
    }


    printf("\nEmployee not found.\n");
}


/* =========================================
   PART 4 - BUDGET MANAGEMENT
   ========================================= */

void budgetManagement(void)
{
    int choice;


    do
    {
        printf("\n========================================\n");
        printf("BUDGET MANAGEMENT\n");
        printf("========================================\n");

        printf("1. Add Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Return to Main Menu\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);


        switch (choice)
        {
            case 1:
                addDepartmentBudget();
                break;

            case 2:
                displayBudgets();
                break;

            case 3:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 3.\n");
        }

    } while (choice != 3);
}


/* =========================================
   ADD DEPARTMENT BUDGET
   ========================================= */

void addDepartmentBudget(void)
{
    if (budgetCount >= MAX_DEPARTMENTS)
    {
        printf("\nDepartment budget storage is full.\n");
        return;
    }


    printf("\n========================================\n");
    printf("ADD DEPARTMENT BUDGET\n");
    printf("========================================\n");


    printf("Enter Department Name: ");
    scanf(" %49[^\n]", budgetDepartments[budgetCount]);


    printf("Enter Allocated Budget: ");
    scanf("%lf", &allocatedBudgets[budgetCount]);


    printf("Enter Expenditure: ");
    scanf("%lf", &expenditures[budgetCount]);


    /* Validate values */

    if (allocatedBudgets[budgetCount] < 0 ||
        expenditures[budgetCount] < 0)
    {
        printf("\nBudget and expenditure cannot be negative.\n");
        return;
    }


    budgetCount++;


    printf("\nDepartment budget added successfully.\n");
}


/* =========================================
   DISPLAY DEPARTMENT BUDGETS
   ========================================= */

void displayBudgets(void)
{
    int i;
    double remaining;


    if (budgetCount == 0)
    {
        printf("\nNo department budgets have been added.\n");
        return;
    }


    printf("\n========================================\n");
    printf("BUDGET REPORT\n");
    printf("========================================\n");


    for (i = 0; i < budgetCount; i++)
    {
        remaining = allocatedBudgets[i] - expenditures[i];


        printf("\nDepartment %d\n", i + 1);
        printf("----------------------------------------\n");

        printf("Department       : %s\n", budgetDepartments[i]);
        printf("Allocated Budget : N$%.2f\n", allocatedBudgets[i]);
        printf("Expenditure      : N$%.2f\n", expenditures[i]);
        printf("Remaining Budget : N$%.2f\n", remaining);


        if (expenditures[i] <= allocatedBudgets[i])
        {
            printf("Status           : WITHIN BUDGET\n");
        }
        else
        {
            printf("Status           : OVER BUDGET\n");
        }
    }
}