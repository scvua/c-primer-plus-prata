//
// pr_pset04_08:
//
// Write a program that asks the user to enter the number of miles traveled
// and the number of gallons of gasoline consumed. It should then calculate
// and display the miles-per-gallon value, showing one place to the right of
// the decimal. Next, using the fact that one gallon is about 3.785 liters and
// one mile is about 1.609 kilometers, it should convert the mile-per-gallon
// value to a liters-per-100-km value, the usual European way of expressing
// fuel consumption, and display the result, showing one place to the right of
// the decimal. Note that the U.S. scheme measures the distance traveled per 
// amount of fuel (higher is better), whereas the European scheme measures
// the amount of fuel per distance (lower is better). Use symbolic constants
// (using const or #define) for the two conversion factors.
//

#include <stdio.h>

#define LIT_IN_GAL 3.785
#define KM_IN_MILE 1.609

int main(void)
{
    float miles, gallons;
    float miles_per_gal, litr_per_km;

    printf("Enter the number of miles traveled: ");
    scanf("%f", &miles);
    printf("Enter the number of gallons of gasoline consumed: ");
    scanf("%f", &gallons);

    miles_per_gal = miles / gallons;
    litr_per_km = (100.0 * gallons * LIT_IN_GAL) / (miles * KM_IN_MILE);

    printf("%.1f miles-per-gallon\n", miles_per_gal);
    printf("%.1f liters-per-100km\n", litr_per_km);

    return 0;
}
