#include <stdio.h>

void decimalToBinary(int n) {
    // Base case
    if (n == 0)
        return;
    
    // Recursively call the function for the quotient
    decimalToBinary(n / 2);
    
    // Print the remainder (0 or 1)
    printf("%d", n % 2);
}

int main() {
    int decimalNumber;
    
    // Input decimal number
    printf("Enter a positive decimal number: ");
    scanf("%d", &decimalNumber);
    
    if (decimalNumber < 0) {
        printf("Please enter a positive decimal number.\n");
        return 1;
    }

    // Convert decimal to binary and print
    printf("Binary representation: ");
    decimalToBinary(decimalNumber);
    printf("\n");
    
    return 0;
}
