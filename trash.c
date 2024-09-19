#include <stdio.h>
int linearSearch(int a[], int n, int p){
    for(int i = 0; i < 5; i++){
        if(a[i] == p)
        return i;
        }
            return -1;
}

void main(){
    int[5];
    int x;
    FILE *fp = fopen("test.txt","r");

    for(int i = 0; i < 5; i ++){
        fscanf(fp, "%d", &a[i]);
    }
    printf("\nEnter a number to search: ");
    scanf("%d", &x);
    int result = linearSearch(a,5,x);
    if(result==-1)
        printf(\n"Number was not found");
    else
        printf("\nElement found. a[%d] = %d", result, a[result]);
}