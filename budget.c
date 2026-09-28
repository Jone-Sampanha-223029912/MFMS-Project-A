#include <stdio.h>
#include "budget.h"
#include "input.h"

#define MAX_DEPARTMENTS 10

char budgetDepartments[MAX_DEPARTMENTS][50];

double allocatedBudgets[MAX_DEPARTMENTS];
double expenditures[MAX_DEPARTMENTS];

int budgetCount = 0;


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

        choice = readInt(
            "Enter your choice: ",
            1,
            3
        );

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
                printf("\nInvalid choice.\n");
        }

    } while (choice != 3);
}


void addDepartmentBudget(void)
{
    if (budgetCount >= MAX_DEPARTMENTS)
    {
        printf("\nDepartment budget storage is full.\n");
        return;
    }

    readText(
        "Enter Department Name: ",
        budgetDepartments[budgetCount],
        sizeof(budgetDepartments[budgetCount])
    );

    allocatedBudgets[budgetCount] =
    readNonNegativeDouble("Enter Allocated Budget: ");

expenditures[budgetCount] =
    readNonNegativeDouble("Enter Expenditure: ");

    if (allocatedBudgets[budgetCount] < 0 ||
        expenditures[budgetCount] < 0)
    {
        printf("\nBudget and expenditure cannot be negative.\n");
        return;
    }

    budgetCount++;

    printf("\nDepartment budget added successfully.\n");
}


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
int getBudgetCount(void)
{
    return budgetCount;
}


double getTotalAllocatedBudget(void)
{
    int i;
    double total = 0.0;

    for (i = 0; i < budgetCount; i++)
    {
        total += allocatedBudgets[i];
    }

    return total;
}


double getTotalExpenditure(void)
{
    int i;
    double total = 0.0;

    for (i = 0; i < budgetCount; i++)
    {
        total += expenditures[i];
    }

    return total;
}


int getOverBudgetCount(void)
{
    int i;
    int count = 0;

    for (i = 0; i < budgetCount; i++)
    {
        if (expenditures[i] > allocatedBudgets[i])
        {
            count++;
        }
    }

    return count;
}