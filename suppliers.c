#include <stdio.h>
#include <string.h>
#include "suppliers.h"

#define MAX_SUPPLIERS 20

int supplierIDs[MAX_SUPPLIERS];

char supplierNames[MAX_SUPPLIERS][100];
char supplierEmails[MAX_SUPPLIERS][100];
char supplierPhones[MAX_SUPPLIERS][30];
char supplierTowns[MAX_SUPPLIERS][50];

int supplierCount = 0;


void supplierManagement(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("SUPPLIER MANAGEMENT\n");
        printf("========================================\n");

        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Return to Main Menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 4.\n");
        }

    } while (choice != 4);
}


void addSupplier(void)
{
    int newID;
    int i;

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier storage is full.\n");
        return;
    }

    printf("\n========================================\n");
    printf("ADD SUPPLIER\n");
    printf("========================================\n");

    printf("Enter Supplier ID: ");
    scanf("%d", &newID);

    if (newID <= 0)
    {
        printf("\nSupplier ID must be greater than 0.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        if (supplierIDs[i] == newID)
        {
            printf("\nSupplier ID already exists.\n");
            return;
        }
    }

    supplierIDs[supplierCount] = newID;

    printf("Enter Supplier Name: ");
    scanf(" %99[^\n]", supplierNames[supplierCount]);

    printf("Enter Email: ");
    scanf(" %99[^\n]", supplierEmails[supplierCount]);

    printf("Enter Phone Number: ");
    scanf(" %29[^\n]", supplierPhones[supplierCount]);

    printf("Enter Town: ");
    scanf(" %49[^\n]", supplierTowns[supplierCount]);

    supplierCount++;

    printf("\nSupplier added successfully.\n");
}


void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been added.\n");
        return;
    }

    printf("\n========================================\n");
    printf("SUPPLIER LIST\n");
    printf("========================================\n");

    for (i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("----------------------------------------\n");

        printf("Supplier ID : %d\n", supplierIDs[i]);
        printf("Name        : %s\n", supplierNames[i]);
        printf("Email       : %s\n", supplierEmails[i]);
        printf("Phone       : %s\n", supplierPhones[i]);
        printf("Town        : %s\n", supplierTowns[i]);
        printf("Name Length : %zu characters\n",
               strlen(supplierNames[i]));
    }
}


void searchSupplier(void)
{
    char searchName[100];
    int i;

    if (supplierCount == 0)
    {
        printf("\nNo suppliers have been added.\n");
        return;
    }

    printf("\nEnter Supplier Name to search: ");
    scanf(" %99[^\n]", searchName);

    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierNames[i], searchName) == 0)
        {
            printf("\n========================================\n");
            printf("SUPPLIER FOUND\n");
            printf("========================================\n");

            printf("Supplier ID : %d\n", supplierIDs[i]);
            printf("Name        : %s\n", supplierNames[i]);
            printf("Email       : %s\n", supplierEmails[i]);
            printf("Phone       : %s\n", supplierPhones[i]);
            printf("Town        : %s\n", supplierTowns[i]);

            return;
        }
    }

    printf("\nSupplier not found.\n");
}