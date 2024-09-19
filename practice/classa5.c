#include<stdio.h>
int main() {

    int num = 10;

    printf("%d", (num==10 && num>=5));
    printf("%d", (num>=5 && num<=50));
    printf("%d", (num!=10 && num>=5));
    printf("%d", (num>=20 && num<=50));
 return 0;
}