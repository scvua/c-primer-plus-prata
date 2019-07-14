/*
 * pr_pset07_10:
 *
 *  **Category**            **Tax**
 *  Single                  15% of first $17,850 plus 28% of excess
 *  Head of Household       15% of first $23,900 plus 28% of excess
 *  Married, Joint          15% of first $29,750 plus 28% of excess
 *  Married, Separate       15% of first $14,875 plus 28% of excess
 *
 *  Write a program that lets the user specify the tax category and the
 *  taxable income and that then calculates the tax. Use a loop so that
 *  the user can enter several tax cases.
 */

#include <stdio.h>

#define TAX     0.15
#define TAXEX   0.28
// Categories:
#define BASE1   17850.0     // Single
#define BASE2   23900.0     // Head of Household
#define BASE3   29750.0     // Married, Joint
#define BASE4   14875.0     // Married, Separate

// Print header with choice.
void printhead(void);
// Calculate the tax and print result.
void taxprint(float base);

int main(void)
{
    int choice;

    printhead();
    while ((scanf("%d", &choice) == 1) && (choice > 0) && (choice < 5))
    {
        switch(choice)
        {
            case 1  :   taxprint(BASE1);
                        break;
            case 2  :   taxprint(BASE2);
                        break;
            case 3  :   taxprint(BASE3);
                        break;
            case 4  :   taxprint(BASE4);
                        break;
            default :   break;
        }
        printf("\n");
        printhead();
    }
    printf("Bye.\n");

    return 0;
}

void printhead(void)
{
    printf("*******************************************************\n");
    printf("Enter the number corresponding to the desired category:\n");
    printf("1) Single\t\t\t2) Head of Household\n");
    printf("3) Married, Joint\t\t4) Married, Separate\n");
    printf("5) quit\n");
    printf("*******************************************************\n");
}

void taxprint(float base)
{
    float income, tax;

    printf("Enter your income:\n");
    while (scanf("%f", &income) != 1)
    {
        printf("Please, try again with one number \n(for example: 213 or 213.00): ");
        while (getchar() != '\n')
            continue;
    }
    if (income > base)
    {
        tax = base * TAX + (income - base) * TAXEX;
    }
    else
    {
        tax = income * TAX;
    }
    printf("Your tax is $%.2f\n", tax);
}
