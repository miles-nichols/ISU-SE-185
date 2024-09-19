#include<stdio.h>

int main()
{

    double miles = 0;
    double mpg = 0;
    double dpg = 0;
    double drivingCosts = 0;

    printf("Enter driven Miles: ");
    scanf("%lf", &miles);
    printf("Enter mile per gallon: ");
    scanf(" %lf", &mpg);
    printf("Enter dollars per gallon:");
    scanf(" %lf", &dpg);

    drivingCosts = (miles / mpg) * dpg;

    printf("Driving costs: %.2lf\n", drivingCosts);


    return 0;
}