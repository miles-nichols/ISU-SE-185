#include <stdio.h>
#include <math.h>

struct Complex {
    double real;
    double imaginary;
};

struct Complex add(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

struct Complex subtract(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real - num2.real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}

struct Complex multiply(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    result.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);
    return result;
}

int main() {
    struct Complex num1, num2, result;

      printf("Enter real and imaginary values for number 1: ");
    if (scanf("%lf %lf", &num1.real, &num1.imaginary) != 2) {
        printf("Invalid input or not enough values provided.\n");
        return 1; 
    }

    printf("Enter real and imaginary values for number 2: ");
    if (scanf("%lf %lf", &num2.real, &num2.imaginary) != 2) {
        printf("Invalid input or not enough values provided.\n");
        return 1; 
    }

    result = add(num1, num2);
    printf("Addition: %.2lf + %.2lfi\n", result.real, result.imaginary);

    result = subtract(num1, num2);
    printf("Subtraction: %.2lf - %.2lfi\n", result.real, result.imaginary);

    result = multiply(num1, num2);
    printf("Multiplication: %.2lf * %.2lfi\n", result.real, result.imaginary);

    return 0;
}