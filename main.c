#include <stdio.h>

#include "employees.h"
#include "budget.h"
#include "suppliers.h"


void displayMainMenu(void);


int main()
{
    char municipality[50];
    char mayor[50];
    int population;

    int choice;

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
                supplierManagement();
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