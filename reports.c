#include <stdio.h>

#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"


void reportsManagement(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("REPORTS\n");
        printf("========================================\n");

        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                employeeReport();
                break;

            case 2:
                budgetReport();
                break;

            case 3:
                supplierReport();
                break;

            case 4:
                assetReport();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 5.\n");
        }

    } while (choice != 5);
}


void employeeReport(void)
{
    if (getEmployeeCount() == 0)
    {
        printf("\nNo employee information available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("EMPLOYEE REPORT\n");
    printf("========================================\n");

    printf("Total Employees : %d\n",
           getEmployeeCount());

    printf("Average Salary  : N$%.2f\n",
           getAverageEmployeeSalary());

    printf("Highest Salary  : N$%.2f\n",
           getHighestEmployeeSalary());

    printf("Lowest Salary   : N$%.2f\n",
           getLowestEmployeeSalary());
}


void budgetReport(void)
{
    double totalBudget;
    double totalExpenditure;
    double remainingBudget;

    if (getBudgetCount() == 0)
    {
        printf("\nNo budget information available.\n");
        return;
    }

    totalBudget = getTotalAllocatedBudget();
    totalExpenditure = getTotalExpenditure();

    remainingBudget = totalBudget - totalExpenditure;

    printf("\n========================================\n");
    printf("BUDGET REPORT\n");
    printf("========================================\n");

    printf("Total Allocated Budget : N$%.2f\n",
           totalBudget);

    printf("Total Expenditure      : N$%.2f\n",
           totalExpenditure);

    printf("Remaining Budget       : N$%.2f\n",
           remainingBudget);

    printf("Departments Over Budget: %d\n",
           getOverBudgetCount());
}


void supplierReport(void)
{
    if (getSupplierCount() == 0)
    {
        printf("\nNo supplier information available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("SUPPLIER REPORT\n");
    printf("========================================\n");

    printf("Total Suppliers: %d\n",
           getSupplierCount());

    displaySuppliers();
}


void assetReport(void)
{
    if (getAssetCount() == 0)
    {
        printf("\nNo asset information available.\n");
        return;
    }

    printf("\n========================================\n");
    printf("ASSET REPORT\n");
    printf("========================================\n");

    printf("Total Assets: %d\n",
           getAssetCount());

    displayAssets();
}