/*
 * pr_pset08_08:
 *
 * Write a program that shows you a menu offering you the choice of
 * addition, subtraction, multiplication, or division.
 * After getting your choice, the program asks for two numbers,
 * then performs the requested operation. The program should accept only
 * the offered menu choices. It should use type float for the numbers
 * and allow the user to try again if he or she fails to enter a number.
 * In the case of division, the program should prompt the user to enter
 * a new value if 0 is entered as the value for the second number.
 */

#include <stdio.h>
#include <ctype.h>

void calc(char);        // Make and print calculations.
char get_choice(void);  // Print menu header and get choice.
char get_first(void);   // Get first letter and skip whitespace characters.
float get_float(void);  // Get float number.
float retry(void);      // Reprompt divisor if it was entered as 0.

int main(void)
{
    int choice;

    while ((choice = get_choice()) != 'q')
    {
        switch(choice)
        {
            case 'a' :  calc('+');
                        break;
            case 's' :  calc('-');
                        break;
            case 'm' :  calc('*');
                        break;
            case 'd' :  calc('/');
                        break;
            default  :  printf("Retry. ");
        }
    }
    printf("Bye.\n");

    return 0;
}

void calc(char sign)
{
    float a, b;
    float value;

    printf("Enter first number: ");
    a = get_float();
    printf("Enter second number: ");
    b = get_float();

    switch(sign)
    {
        case '+' :  value = a + b;
                    break;
        case '-' :  value = a - b;
                    break;
        case '*' :  value = a * b;
                    break;
        case '/' :  while (b == 0)
                        b = retry();
                    value = a / b;
    }
    printf("%g %c %g = %g\n", a, sign, b, value);
}

char get_choice(void)
{
    char ch;

    printf("Enter the operation of your choice:\n");
    printf("a. add           s. subtract\n"
           "m. multiply      d. divide\n");
    printf("q. quit\n");
    ch = get_first();
    while (ch != 'a' && ch != 's' && ch != 'm' && ch !='d' && ch != 'q')
    {
        printf("Please respond with a, d, m, s or q.\n");
        ch = get_first();
    }

    return ch;
}

char get_first(void)
{
    char ch;

    ch = getchar();
    while (!isalpha(ch))
    {
        if (ch == '\n')
            printf("Retry with a letter: ");
        ch = getchar();
    }
    while (getchar() != '\n')
        continue;

    return ch;
}

float get_float(void)
{
    float num;
    char ch;

    while (scanf("%f", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }
    while (getchar() != '\n')
        continue;

    return num;
}

float retry(void)
{
    printf("Enter a number other than 0: ");

    return get_float();
}
