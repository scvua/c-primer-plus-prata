//
//  pr_pset03_05.c
//  Write a program that requests your age in years and then displays
//  the equivalent number of seconds.
//

#include <stdio.h>

int main(void)
{
    const float secs_in_year = 3.156e7;
    int years;
    float age_of_user;

    printf("Enter your age in years: ");
    scanf("%d", &years);
    age_of_user = years * secs_in_year;
    printf("Your age in seconds is %e or %f\n",
            age_of_user, age_of_user);

    return 0;
}
