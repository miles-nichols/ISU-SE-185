#include <stdio.h>

int main(){
int x[3] = {9, 10, 11};      
int *my_ptr = x;     
printf("%d", *my_ptr); 

return 0;
}