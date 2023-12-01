#include <stdio.h>

// Declare the external assembly function
extern int findGCDFunc(int num1, int num2);

int main(int argc, char *argv[]) {
    int num1, num2;

    // Prompt the user to enter two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Call the assembly function to find the GCD
    int gcd = findGCDFunc(num1, num2);

    // Display the result
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd);

    return 0;
}
