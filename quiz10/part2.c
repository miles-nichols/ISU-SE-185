#include <stdio.h>

// Function prototype
double power(double base, int exponent);

int main() {
    double base;
    int exponent;

    // Get input from the user
    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    // Call the power function and display the result
    printf("%.2lf ^ %d = %.2lf\n", base, exponent, power(base, exponent));

    return 0;
}

// Recursive function to calculate power
double power(double base, int exponent) {
    // Base case: any number to the power of 0 is 1
    if (exponent == 0) {
        return 1.0;
    }

    // Recursive case: base ^ exponent = base * base ^ (exponent - 1)
    return base * power(base, exponent - 1);
}
