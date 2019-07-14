/*
 *  pr_pset12_02a.h -- constants and declaration for pr_pset12_02a.c
 *  Created by gres.cher on 01/24/19.
 */

// Definition of mode values
#define METRIC 0
#define US 1
// Definition of the string shortenings
// Consumption
#define CONS_PRINT "Fuel consumption is "
#define CONS_M "liters per 100 km."
#define CONS_US "miles per gallon."
// Distance
#define DIST_PROMPT "Enter distance traveled in"
#define DIST_M "kilometers"
#define DIST_US "miles"
// Fuel
#define FUEL_PROMPT "Enter fuel consumed in"
#define FUEL_M "litres"
#define FUEL_US "gallons"
// Mode notifications
#define INVALID "Invalid mode specified. Mode "
#define MODE_M "(metric) used."
#define MODE_US "(US) used."

// Set up interface mode; if `n` doesn't match use previous mode
void set_mode(int m);

// Prompt the data according to the mode; store in 'distance' & 'fuel'
void get_info(void);

// Calculate and display the result based on the mode setting
void show_info(void);
