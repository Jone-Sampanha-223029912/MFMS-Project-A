#include <stdio.h>
#include "assets.h"

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

        printf("Enter your choice: ");
        scanf("%d", &choice);

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

    printf("Enter Asset ID: ");
    scanf("%d", &newID);

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

    printf("Enter Asset Name: ");
    scanf(" %49[^\n]", assetNames[assetCount]);

    printf("Enter Asset Type: ");
    scanf(" %49[^\n]", assetTypes[assetCount]);

    printf("Enter Purchase Value: ");
    scanf("%lf", &purchaseValues[assetCount]);

    if (purchaseValues[assetCount] < 0)
    {
        printf("\nPurchase value cannot be negative.\n");
        return;
    }

    printf("Enter Department: ");
    scanf(" %49[^\n]", assetDepartments[assetCount]);

    printf("Enter Condition: ");
    scanf(" %29[^\n]", assetConditions[assetCount]);

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

    printf("\nEnter Asset ID to search: ");
    scanf("%d", &searchID);

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