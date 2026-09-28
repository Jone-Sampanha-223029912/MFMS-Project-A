#include <stdio.h>

int main()
{
    int choice;

    do
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

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Employee Management selected.\n");
                break;

            case 2:
                printf("Budget Management selected.\n");
                break;

            case 3:
                printf("Supplier Management selected.\n");
                break;

            case 4:
                printf("Asset Management selected.\n");
                break;

            case 5:
                printf("Reports selected.\n");
                break;

            case 6:
                printf("Exiting system. Goodbye.\n");
                break;

            default:
                printf("Invalid choice. Please select 1 to 6.\n");
        }

    } while (choice != 6);

    return 0;
}