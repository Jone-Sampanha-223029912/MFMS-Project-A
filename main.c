#include <stdio.h>

int main()
{
    char municipality[50];

    printf("Municipal Financial Management System\n");
    printf("Welcome to Windhoek Municipality\n");

    printf("Enter Municipality Name: ");
    scanf("%49s", municipality);

    printf("Municipality: %s\n", municipality);

    return 0;
}