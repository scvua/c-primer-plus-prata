/*
 * pr_pset07_11:
 *
 *  Write a program that uses a switch statement in a loop such that a response
 *  of a lets the user enter the pounds of artichokes desired, b the pounds of
 *  beets, c the pounds of carrots, and q allows the user to exit the ordering
 *  process. The program should keep track of cumulative totals. That is, if
 *  the user enters 4 pounds of beets and later enters 5 pounds of beets,
 *  the program should use report 9 pounds of beets. The program then should
 *  compute the total charges, the discount, if any, the shipping charges,
 *  and the grand total. The program then should display all the purchase
 *  information: the cost per pound, the pounds ordered, and the cost for that
 *  order for each vegetable, the total cost of the order, the discount
 *  (if there is one), the shipping charge, and the grand total of all
 *  the charges.
 */

#include <stdio.h>

#define ARTICH_PRICE    2.05
#define BEETS_PRICE     1.15
#define CARROT_PRICE    1.09
#define ORDER_BASE      100.0
#define DISCOUNT        0.05
#define WEIGHT_BASE1    5
#define WEIGHT_BASE2    20
#define SHIP_COST1      6.5
#define SHIP_COST2      14.0
#define SHIP_COST_EX    0.5

// Print header menue.
void printheader(void);
// Ask user for pounds.
float get_weight(void);
// Calculate, print and return product's charge
float set_charge(char name[], float weight, float prise);

int main(void)
{
    int choice;
    float w_artich, w_beet, w_carrot;   // cumulative totals of weight
    float weight = 0.0;                 // total order's weight
    float total = 0.0;                  // grand total
    float discount = 0.0;
    float shipping;

    w_artich = w_beet = w_carrot = 0.0;
    printheader();
    while (((choice = getchar()) != 'q') && (choice != 'Q'))
    {
        switch(choice)
        {
            case 'a' :
            case 'A' :  w_artich += get_weight();
                        break;
            case 'b' :
            case 'B' :  w_beet += get_weight();
                        break;
            case 'c' :
            case 'C' :  w_carrot += get_weight();
                        break;
            default  :  printf("Retry with letter (a,b,c or q).\n");
                        break;
        }
        while (getchar() != '\n')
            continue;
        printheader();
    }
    weight = w_artich + w_beet + w_carrot;
    if (weight > 0)
    {
        printf("**********************************\n");
        // Calculate total and print product charge.
        if (w_artich > 0)
        {
            total += set_charge("Artichokes", w_artich, ARTICH_PRICE);
        }
        if (w_beet > 0)
        {
            total += set_charge("Beets     ", w_beet, BEETS_PRICE);
        }
        if (w_carrot > 0)
        {
            total += set_charge("Carrots   ", w_carrot, CARROT_PRICE);
        }
        printf("Total                    : $%6.2f\n", total);
        // Calculate and print discount.
        if (total >= ORDER_BASE)
        {
            discount = total * DISCOUNT;
            printf("Discount (5%%)            : $%6.2f\n", discount);
        }
        // Calculate and print shipping and handling
        if (weight <= WEIGHT_BASE1)
        {
            shipping = SHIP_COST1;
        }
        else if (weight <= WEIGHT_BASE2)
        {
            shipping = SHIP_COST2;
        }
        else
        {
            shipping = SHIP_COST2 + SHIP_COST_EX * (weight - WEIGHT_BASE2);
        }
        printf("Shipping of\t%5.1f lbs: $%6.2f\n", weight, shipping);
        // Print grand total charge.
        printf("**********************************\n");
        printf("TOTAL                    : $%6.2f\n",
                total - discount + shipping);
    }

    return 0;
}

void printheader(void)
{
    printf("******************************************************\n");
    printf("Enter the letter corresponding to the desired product:\n");
    printf("a) artichokes\tb) beets\tc) carrots\n");
    printf("q) quit\n");
    printf("******************************************************\n");
}

float get_weight(void)
{
    float pounds;

    printf("Enter weight (in pounds): ");
    while (scanf("%f", &pounds) != 1 && (pounds < 0))
    {
        printf("Please, retry with some positive number: ");
        while (getchar () != '\n')
            continue;
    }

    return pounds;
}

float set_charge(char name[10], float weight, float prise)
{
    float charge;

    charge = weight * prise;
    printf("%s\t%5.1f lbs: $%6.2f\n", name, weight, charge);

    return charge;
}
