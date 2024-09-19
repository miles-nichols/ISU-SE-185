#include <stdio.h>

int main() {
    int numRows, numColumns;
    
    // Input numRows and numColumns
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns: ");
    scanf("%d", &numColumns);
    
    // Loop through rows and columns to print the seats
    for (int row = 1; row <= numRows; row++) {
        for (int column = 'A'; column < 'A' + numColumns; column++) {
            printf("%d%c ", row, column);
        }
    }
    
    printf("\n");
    
    return 0;
}