//
//  pr_pset03_06.c
//
//  The mass of a single molecule of water is about 3.0×10^-23 grams.
//  A quart of water is about 950 grams.
//  Write a program that requests an amount of water, in quarts,
//  and displays the number of water molecules in that amount.
//

#include <stdio.h>

int main(void)
{
    const float grams_in_quart = 950.0;
    const float mass_of_molecule = 3e-23;
    float quarts, molekules;
    
    // Ask the user for the number of quarts
    printf("Enter an amount of water: ");
    scanf("%f", &quarts);
    // Calculate the number of water molekules
    molekules = (quarts * grams_in_quart) / mass_of_molecule;
    // Print results
    printf("Number of water molekules in %.2f quart(s) of water:",
            quarts);
    printf("\n%e\n", molekules);
    
    return 0;
}
