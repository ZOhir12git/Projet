#include <stdio.h>
#include "calculte.h"

int main() {
    int a, b;
    char operation;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    int result;

    switch (operation) {
        case '+':
            result = add(a, b);
            printf("Result: %d\n", result);
            break;
        case '-':
            result = sub(a, b);
            printf("Result: %d\n", result);
            break;
        case '*':
            result = mult(a, b);
            printf("Result: %d\n", result);
            break;
        case '/':
            if (b != 0) {
                result = div(a, b);
                printf("Result: %d\n", result);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }

    return 0;
}