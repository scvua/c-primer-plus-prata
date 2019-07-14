//
// pr_pset04_04:
//
// Write a program that requests your height in inches and your name, and then 
// displays the information in the following form:
//
//     Dabney, you are 6.208 feet tall
//
// Use type float, and use / for division. If you prefer, request the height
// in centimeters and display it in meters.
//

#include <stdio.h>

int main(void)
{
    char name[20];
    float height;

    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your height in centimeters: ");
    scanf("%f", &height);

    // Convert centimeters into meters.
    height = height / 100.0;

    printf("%s, you are %.2f meters tall.\n", name, height);

    return 0;
}
