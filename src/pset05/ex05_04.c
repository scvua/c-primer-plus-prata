//
// pr_pset05_04:
//
// Write a program that asks the user to enter a height in centimeters and
// then displays the height in centimeters and in feet and inches. Fractional
// centimeters and inches should be allowed, and the program should allow
// the user to continue entering heights until a nonpositive value is entered.
// A sample run should look like this:
//
//     Enter a height in centimeters: 182
//     182.0 cm = 5 feet, 11.7 inches
//     Enter a height in centimeters (<=0 to quit): 168.7
//     168.0 cm = 5 feet, 6.4 inches
//     Enter a height in centimeters (<=0 to quit): 0
//     bye
//

#include <stdio.h>

#define CM_IN_FOOT 30.48
#define CM_IN_INCH 2.54

int main(void)
{
    float cm, inch;
    int feet;

    printf("Enter a height in centimeters: ");
    scanf("%f", &cm);
    while (cm > 0)
    {
        printf("%.1f cm = ", cm);
        feet = (int) (cm / CM_IN_FOOT);
        cm = cm - (float) feet * CM_IN_FOOT;
        inch = cm / CM_IN_INCH;
        printf("%d feet, %.1f inches.\n", feet, inch);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &cm);
    }
    printf("bye\n");

    return 0;
}
