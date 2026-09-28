#include <stdio.h>

int main()
{
    char municipality[50];
    char mayor[50];

    printf("Municipal Financial Management System\n");
    printf("Welcome to Windhoek Municipality\n");

    printf("Enter Municipality Name: ");
    scanf("%49s", municipality);

    printf("Enter Mayor Name: ");
    scanf("%49s", mayor);

    printf("\nMunicipality: %s\n", municipality);
    printf("Mayor: %s\n", mayor);

    return 0;
}