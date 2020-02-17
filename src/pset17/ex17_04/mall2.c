/*
 * mall2.c -- version of mall.c (listing 17.7) so that it simulates
 * a double booth having two queues.
 * Compile with queue.c
 */
#include <stdio.h>
#include <stdlib.h>     // for rand() and srand()
#include <time.h>       // for time()
#include "queue.h"
#define MIN_PER_HR  60.0

// Define Booth type with its own queue and parameters
typedef struct booth
{
    Queue line;
    long sum_line;          // cumulative line length
    int wait_time;          // time until booth is free
    long line_wait;         // cumulative time in line
    long served;            // served by the booth during the simulation
} Booth;

bool newcustomer(double x);             // is there a new customer?
Item customertime(long when);           // set customer parameters
void initializeBooth(Booth * pb);       // initialize booth (queue and params)
void checkBooth(Booth * pb, long when); // check a booth line status

int main(void)
{
    Booth booth1, booth2;   // lines for first and second boothes
    Item temp;              // new customer data
    int hours;              // hours of simulation
    int perhour;            // average # of arrivals per hour
    long cycle, cyclelimit; // loop counter, limit
    long turnaways = 0;     // turned away by full queue
    long customers = 0;     // joined the queue
    double min_per_cust;    // average time between arrivals

    initializeBooth(&booth1);
    initializeBooth(&booth2);
    srand((unsigned int) time(0)); // random initializing of rand()
    puts("Case Study: Sigmund Lander's Advice Boothes");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;
    
    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&booth1.line) && QueueIsFull(&booth2.line))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                // add a customer to a shorter queue
                if (QueueItemCount(&booth1.line) <= QueueItemCount(&booth2.line))
                    EnQueue(temp, &booth1.line);
                else
                    EnQueue(temp, &booth2.line);
            }
        }
        checkBooth(&booth1, cycle);
        checkBooth(&booth2, cycle);
    }

    if (customers > 0)
    {
        printf("         customers accepted: %ld\n", customers);
        printf("  customers served (booth1): %ld\n", booth1.served);
        printf("  customers served (booth2): %ld\n", booth2.served);
        printf("   customers served (total): %ld\n", 
                booth1.served + booth2.served);
        printf("                  turnaways: %ld\n", turnaways);
        printf("average queue size (booth1): %.2f\n",
                (double) booth1.sum_line / cyclelimit);
        printf("average queue size (booth2): %.2f\n",
                (double) booth2.sum_line / cyclelimit);
        printf(" average queue size (total): %.2f\n",
                ((double) booth1.sum_line + booth2.sum_line) / 
                    (2.0 * cyclelimit));
        printf(" average wait time (booth1): %.2f minutes\n",
                (double) booth1.line_wait / booth1.served);
        printf(" average wait time (booth2): %.2f minutes\n",
                (double) booth2.line_wait / booth2.served);
        printf("  average wait time (total): %.2f minutes\n", 
                ((double) booth1.line_wait / booth1.served + 
                 (double) booth2.line_wait / booth2.served) / 2.0);
    }
    else
        puts("No customers!");
    EmptyTheQueue(&booth1.line);
    EmptyTheQueue(&booth2.line);
    puts("Bye!");

    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}

// pb points to a booth; queue of the booth and all its 
// parameters are initialized to being empty
void initializeBooth(Booth * pb)
{
    InitializeQueue(&pb->line);
    pb->sum_line = 0;
    pb->wait_time = 0;
    pb->line_wait = 0;
    pb->served = 0;
}

// check whether booth is free at current time;
// if it isn't occupied remove the client at the front of the queue,
// determine wait time for next client, update time spent in line
// and length of the line to current time
void checkBooth(Booth * pb, long current_time)
{
    if (pb->wait_time <= 0 && !QueueIsEmpty(&pb->line))
    {
        Item temp;
        DeQueue(&temp, &pb->line);
        pb->wait_time = temp.processtime;
        pb->line_wait += current_time - temp.arrive;
        pb->served++;
    }
    if (pb->wait_time > 0)
        pb->wait_time--;
    pb->sum_line += QueueItemCount(&pb->line);
}
