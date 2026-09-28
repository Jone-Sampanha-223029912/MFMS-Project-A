#include <stdio.h>
#include "assets.h"
#include "input.h"

#define MAX_ASSETS 30

int assetIDs[MAX_ASSETS];

char assetNames[MAX_ASSETS][50];
char assetTypes[MAX_ASSETS][50];
char assetDepartments[MAX_ASSETS][50];
char assetConditions[MAX_ASSETS][30];

double purchaseValues[MAX_ASSETS];

int assetCount = 0;


void assetManagement(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("ASSET MANAGEMENT\n");
        printf("========================================\n");

        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Return to Main Menu\n");

        choice = readInt(
            "Enter your choice: ",
            1,
            4
        );

        switch (choice)
        {
            case 1:
                addAsset();
                break;

            case 2:
                displayAssets();
                break;

            case 3:
                searchAsset();
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please select 1 to 4.\n");
        }

    } while (choice != 4);
}


void addAsset(void)
{
    int newID;
    int i;

    if (assetCount >= MAX_ASSETS)
    {
        printf("\nAsset storage is full.\n");
        return;
    }

    printf("\n========================================\n");
    printf("ADD ASSET\n");
    printf("========================================\n");

    newID = readInt(
        "Enter Asset ID: ",
        1,
        999999999
    );

    if (newID <= 0)
    {
        printf("\nAsset ID must be greater than 0.\n");
        return;
    }

    for (i = 0; i < assetCount; i++)
    {
        if (assetIDs[i] == newID)
        {
            printf("\nAsset ID already exists.\n");
            return;
        }
    }

    assetIDs[assetCount] = newID;

    readText(
        "Enter Asset Name: ",
        assetNames[assetCount],
        sizeof(assetNames[assetCount])
    );

    readText(
        "Enter Asset Type: ",
        assetTypes[assetCount],
        sizeof(assetTypes[assetCount])
    );

    purchaseValues[assetCount] = readNonNegativeDouble(
        "Enter Purchase Value: "
    );

    if (purchaseValues[assetCount] < 0)
    {
        printf("\nPurchase value cannot be negative.\n");
        return;
    }

    readText(
        "Enter Department: ",
        assetDepartments[assetCount],
        sizeof(assetDepartments[assetCount])
    );

    readText(
        "Enter Condition: ",
        assetConditions[assetCount],
        sizeof(assetConditions[assetCount])
    );

    assetCount++;

    printf("\nAsset added successfully.\n");
}


void displayAssets(void)
{
    int i;

    if (assetCount == 0)
    {
        printf("\nNo assets have been added.\n");
        return;
    }

    printf("\n========================================\n");
    printf("ASSET REGISTER\n");
    printf("========================================\n");

    for (i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("----------------------------------------\n");

        printf("Asset ID       : %d\n", assetIDs[i]);
        printf("Asset Name     : %s\n", assetNames[i]);
        printf("Asset Type     : %s\n", assetTypes[i]);
        printf("Purchase Value : N$%.2f\n", purchaseValues[i]);
        printf("Department     : %s\n", assetDepartments[i]);
        printf("Condition      : %s\n", assetConditions[i]);
    }
}


void searchAsset(void)
{
    int searchID;
    int i;

    if (assetCount == 0)
    {
        printf("\nNo assets have been added.\n");
        return;
    }

    searchID = readInt(
        "\nEnter Asset ID to search: ",
        1,
        999999999
    );

    for (i = 0; i < assetCount; i++)
    {
        if (assetIDs[i] == searchID)
        {
            printf("\n========================================\n");
            printf("ASSET FOUND\n");
            printf("========================================\n");

            printf("Asset ID       : %d\n", assetIDs[i]);
            printf("Asset Name     : %s\n", assetNames[i]);
            printf("Asset Type     : %s\n", assetTypes[i]);
            printf("Purchase Value : N$%.2f\n", purchaseValues[i]);
            printf("Department     : %s\n", assetDepartments[i]);
            printf("Condition      : %s\n", assetConditions[i]);

            return;
        }
    }

    printf("\nAsset not found.\n");
}
int getAssetCount(void)
{
    return assetCount;
}