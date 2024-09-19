#include <stdio.h>
#include <stdlib.h>

int main(){

int num = 5;
int *pNum = &num; //pointing pNum to num

printf("num is stored at: %p\n", &num); //%d prints address while %d prints value
printf("myPtr is stored at: %p\n", &pNum);
printf("num holds the value: %d\n", num);
printf("myPtr holds the value: %d\n", pNum);
printf("myPrr points to this value: %d", num);

return 0;
}