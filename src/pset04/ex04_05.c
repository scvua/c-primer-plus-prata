//
// pr_pset04_05:
//
// Write a program that requests the download speed in megabits per second (Mbs)
// and the size of a file in megabytes (MB). The program should calculate
// the download time for the file. Note that in this context one byte is eight
// bits. Use type float, and use / for division. The program should report all
// three values (download speed, file size, and download time) showing two digits
// to the right of the decimal point, as in the following:
//
//     At 18.12 megabits per second, a file of 2.20 megabytes
//     downloads in 0.97 seconds.
//

#include <stdio.h>

#define BITS 8

int main(void)
{
    float speed, size, dtime;

    printf("Enter the download speed (Mbs):\n");
    scanf("%f", &speed);
    printf("Enter the size of a file (MB):\n");
    scanf("%f", &size);
    printf("At %.2f megabits per second, a file of %.2f megabytes ",
            speed, size);

    size = size * BITS;     // Convert size to Mb
    dtime = size / speed;
    printf("downloads in %.2f seconds.\n", dtime);

    return 0;
}
