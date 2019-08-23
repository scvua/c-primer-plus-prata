/*
 *  ex16_03.c
 *  The program that reads the magnitude and angle (in degrees) of a vector and
 *  then displays the x and y components.
 *  Created by gres.cher on 08/23/19.
 */

#include <math.h>
#include "psets.h"
#include <stdio.h>

typedef struct {
    double radius;
    double angle;
} polar_s;

typedef struct {
    double x;
    double y;
} rect_s;

rect_s ptor(const polar_s *);

int main(void)
{
    rect_s v_rec;
    polar_s v_pol;

    puts("Enter a magnitude: ");
    while (scanf("%lf", &v_pol.radius) == 1)
    {
        EATLINE();
        puts("Enter an angle (in degrees):");
        if (scanf("%lf", &v_pol.angle) != 1)
        {
            EATLINE();
            puts("Incorrect angle. Try again from the beginning");
            puts("Enter a magnitude; (q to quit):");
            continue;
        }
        EATLINE();
        printf("r = %7.3lf;   angle = %7.3lf\n", v_pol.radius, v_pol.angle);
        v_rec = ptor(&v_pol);
        printf("x = %7.3lf;       y = %7.3lf\n", v_rec.x, v_rec.y);
        puts("Enter a magnitude; (q to quit):");
    }
    puts("Bye.");

    return 0;
}

// Convert polar coordinates to rectangle coordinates
rect_s ptor(const polar_s * polar)
{
    // Convert degrees to radians
    double angle_rad = DEG_TO_RAD(polar->angle);
    rect_s rect;

    rect.x = polar->radius * cos(angle_rad);
    rect.y = polar->radius * sin(angle_rad);
    return rect;
}
