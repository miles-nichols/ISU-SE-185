#include<stdio.h>

/*Re-implement the following code by defining int copy_a as an integer pointer variable called ptr_a. Keep int as an integer variable.*/

/*int main() {
    int a = 15;
    int copy_a = a;
    a /= 3;
    copy_a = a;

    copy_a++;
    a = copy_a;

    if(copy_a == a) {
        printf("Copy_a = %d\n" , copy_a);
        printf("a = %d\n" , a);
        printf("Therefore, copy_a = a = %d\n" , copy_a);
    }

    return 0;
}*/

int main(){
    int a = 15;
    int *ptr_a = &a;
    a /= 3;

    ++(*ptr_a);
    a = *ptr_a;

    if(*ptr_a == a){
        printf("Copy_a = %d\n", *ptr_a);
        printf("a = %d\n", a);
        printf("Therefore, Copy_a = a = %d\n", *ptr_a);
    }

return 0;
}