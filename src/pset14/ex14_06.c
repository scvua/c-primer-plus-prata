/*
 *  pr_pset14_06.c
 *
 *  A text file holds information about a softball team. Each line has data
 *  arranged as follows:
 *
 *      4 Jessie Joybat 5 2 1 1
 *
 *  The first item is the player’s number, conveniently in the range 0–18. The
 *  second item is the player’s first name, and the third is the player’s last
 *  name. Each name is a single word. The next item is the player’s official
 *  times at bat, followed by the number of hits, walks, and runs batted in
 *  (RBIs). The file may contain data for more than one game, so the same player
 *  may have more than one line of data, and there may be data for other players
 *  between those lines. Write a program that stores the data into an array of
 *  structures. The structure should have members to represent the first and
 *  last names, the at bats, hits, walks, and RBIs (runs batted in), and the
 *  batting average (to be calculated later). You can use the player number as
 *  an array index. The program should read to end-of-file, and it should keep
 *  cumulative totals for each player.
 *
 *  All this program has to do is read and process the data file, as described
 *  next, without worrying about how realistic the data is.
 *
 *  The simplest way for the program to proceed is to initialize the structure
 *  contents to zeros, read the file data into temporary variables, and then add
 *  them to the contents of the corresponding structure. After the program has
 *  finished reading the file, it should then calculate the batting average for
 *  each player and store it in the corresponding structure member. The batting
 *  average is calculated by dividing the cumulative number of hits for a player
 *  by the cumulative number of at-bats; it should be a floating-point calculation.
 *  The program should then display the cumulative data for each player along
 *  with a line showing the combined statistics for the entire team.
 *
 *  Created by gres.cher on 04/28/19.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSIZE 81
#define NSIZE 15
#define NUMS 19

typedef unsigned short Score;

// In this structure, Score variables might be an array of 4 numbers,
// but I decided to leave them their names
typedef struct {
    char fname[NSIZE];
    char lname[NSIZE];
    Score atbat;
    Score hits;
    Score walks;
    Score rbi;
    float avrbat;
} Stats;

float avercalc(const Stats * pst);
void printline(int n, const Stats * pst);
void readline(Stats * pst, FILE * fp);
char * readname(char *st, int lim, FILE *fp);

int main(void)
{
    char filename[LSIZE];
    FILE *fp;
    Stats player[NUMS+1] = {0};
    Score num;
    
    // Open file
    printf("Input the file address:\n");
    scanf("%s", filename);
    if ((fp = fopen(filename, "r")) == NULL)
    {
        printf("Couln't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    // Read file into structure array
    while ((fscanf(fp, "%hd", &num)) == 1 && num < NUMS)
        readline(&player[num], fp);
    // Calculate the batting average
    for (int i = 0; i < NUMS; i++)
        player[i].avrbat = avercalc(&player[i]);
    
    // Calculate totals for the total team (the player[NUMS] structure)
    strcpy(player[NUMS].fname, "TOTAL");
    for (int i = 0; i < NUMS; i++)
    {
        player[NUMS].atbat += player[i].atbat;
        player[NUMS].hits += player[i].hits;
        player[NUMS].walks += player[i].walks;
        player[NUMS].rbi += player[i].rbi;
    }
    player[NUMS].avrbat = avercalc(&player[NUMS]);
    
    // Print the table with scores; player[NUMS] has the Team's Total Scores
    for (int i = 0; i <= NUMS; i++)
        printline(i, &player[i]);
    
    fclose(fp);
    
    return 0;
}

// Calculate the batting average for a player
float avercalc(const Stats * pst)
{
    if (pst->atbat > 0)
        return ((float) pst->hits / (float) pst->atbat);
    else
        return 0.0;
}

// Prints structure if its first name record is not empty
void printline(int n, const Stats * pst)
{
    char temp[NSIZE + NSIZE]; // for sprintf() use
    if (pst->fname[0] != 0)
    {
        // Print names
        if (pst->lname[0] != 0)
        {
            // Player has the first and the last names
            sprintf(temp, "%s %s", pst->fname, pst->lname);
            printf("%20s:  ", temp);
        }
        else
            // Player has only the first name
            printf("%20s:  ", pst->fname);
        // Print scores
        printf("%2hd %2hd %2hd %2hd\t",
               pst->atbat, pst->hits, pst->walks, pst->rbi);
        // Print average
        printf("%.2f\n", pst->avrbat);
    }
}

// Read a line from the source file
void readline(Stats * pst, FILE * fp)
{
    Score tmp;
    
    // Read names
    readname(pst->fname, NSIZE, fp);
    readname(pst->lname, NSIZE, fp);
    
    // Read points to temporary variable; add tmp value to previous results
    fscanf(fp, "%hd", &tmp);
    pst->atbat += tmp;
    fscanf(fp, "%hd", &tmp);
    pst->hits += tmp;
    fscanf(fp, "%hd", &tmp);
    pst->walks += tmp;
    fscanf(fp, "%hd", &tmp);
    pst->rbi += tmp;
}

// Read one word; skip forhanded space; end reading at the whitespace or a digit
char * readname(char *st, int lim, FILE *fp)
{
    int ch;
    char *ret_val = NULL;
    
    while (--lim > 0 && (ch = getc(fp)) != EOF && ch != '\n')
    {
        if (isalpha(ch))
        {
            // At first letter assign string address to ret_val
            if (ret_val == NULL)
                ret_val = st;
            *st++ = ch;
        }
        else
        {
            if (isspace(ch) && ret_val == NULL)
                continue;	// There was no letter yet
            else
            {
                // Finalize the string and exit loop
                *st = '\0';
                if (isdigit(ch))
                {
                    // This block is for the case when there is no space between
                    // a name and a score in the source file
                    fseek(fp, ftell(fp)-1, SEEK_SET);
                    // Move the position in the file by one step back
                }
                break;
            }
        }
    }
    // Finalize the string if it has any letter
    if (ret_val)
        *st = '\0';
    
    return ret_val;
}
