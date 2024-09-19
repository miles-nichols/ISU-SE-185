#include <stdio.h>
#include <math.h>

double Sum(int n){
    if(n == 1){
        return 1;
    }
    else{
        return Sum *= n * (1 / pow(2, n)); 
        return (n-1);   
    }
}

int main(){
    double Sum(int n);
    printf("For n = 10, the sum of the sequence is: %lf", Sum(10));
}