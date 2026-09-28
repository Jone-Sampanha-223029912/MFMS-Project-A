#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "input.h"

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

        choice = readInt(
            "Enter your choice: ",
            1,
            4
        );

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

    newID = readInt(
        "Enter Supplier ID: ",
        1,
        999999999
    );

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

    readText(
        "Enter Supplier Name: ",
        supplierNames[supplierCount],
        sizeof(supplierNames[supplierCount])
    );

    readText(
        "Enter Email: ",
        supplierEmails[supplierCount],
        sizeof(supplierEmails[supplierCount])
    );

    readText(
        "Enter Phone Number: ",
        supplierPhones[supplierCount],
        sizeof(supplierPhones[supplierCount])
    );

    readText(
        "Enter Town: ",
        supplierTowns[supplierCount],
        sizeof(supplierTowns[supplierCount])
    );

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

    readText(
        "\nEnter Supplier Name to search: ",
        searchName,
        sizeof(searchName)
    );

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
int getSupplierCount(void)
{
    return supplierCount;
}