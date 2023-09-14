// KIT107 Assignment 2
/*
 * Implementation for driver
 *
 * Author Julian Dermoudy
 * Version 23/8/2023
 *
 * THIS FILE IS COMPLETE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "route.h"
#include "collection.h"


/* Global Variables */

collection the_collection;	// the collection!


/* Functions*/

void read_in_data()
{
	const char *FILENAME = "data.csv";	// the name of the text file
	const int LIMIT = 10;			// set to a small number, e.g. 10 when debugguing
	const int MAX_LINE_LENGTH = 120;	// maximum length of any line in the text file

	char *line;			// a line of text from the file
	char *tokens;		// the line of text broken up into a stream of vertical-bar separated tokens
	int year;			// the year from the line of text
	int month;			// the month from the line of text
	char *port1;		// port 1 from the line of text
	char *port2;		// port 2 from the line of text
	char *description;	// the description from the line of text
	double price_then;	// the price at time of route from the line of text
	double price_now;	// the price now from the line of text
	FILE *fp;			// the file itself

	route a_route;		// a route
	int count = 0;		// the number of lines (routes) read from the file

	// open the file
	fp = fopen(FILENAME, "r");
	if (fp == NULL)
	{
		// couldn't open the file, so quit
		fprintf(stderr,"Cannot open file.\n");
		exit(1);
	}
	else
	{
		line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));

		// read in all the route data, one line at a time
		while (fscanf(fp, "%[^\n]\n", line) != EOF)
		{
			// skip comments
			if (line[0] != '#')
			{
				count++;
				// stop at LIMIT (if required for debugging)
				if (count <= LIMIT)
				{
					// printf("count is %d\t",count);	// uncomment when debugging
					// printf("%s\n", line);	// uncomment when debugging

					// break up input line into components
					tokens = strtok(line, ",");
					year = atoi(tokens);
					//(char *)malloc(10 * sizeof(char));
					//sprintf(date, "%s", tokens);

					tokens = strtok(NULL, ",");
					month = atoi(tokens);
					
					tokens = strtok(NULL, ",");
					port1 = (char *)malloc(20 * sizeof(char));
					sprintf(port1, "%s", tokens);

					tokens = strtok(NULL, ",");
					port2 = (char *)malloc(20 * sizeof(char));
					sprintf(port2, "%s", tokens);

					tokens = strtok(NULL, ",");
					description = (char *)malloc(30 * sizeof(char));
					sprintf(description, "%s", tokens);


					tokens = strtok(NULL, ",");
					price_then = atof(tokens);

					tokens = strtok(NULL, ",");
					price_now = atof(tokens);

					// create a route based on the components of input line
					init_route(&a_route, year, month, port1, port2, description, price_then, price_now);
					//printf("%s\n", to_string(a_route));	// uncomment when debugging

					// add created route to the collection
					add_route_to_collection(the_collection, a_route);
				}
			}
		}
	}
	fclose(fp);
}

/*
* Entry point
*/
int main(int argc, char *argv[])
{
	// print and underline heading
	printf("Australian Air Routes\n");
	printf("=====================\n\n");

	// initialise collection
	init_collection(&the_collection);
	
	// read data in from file and fill data structures
	read_in_data();

	// process and show the results
	route_changes(the_collection);
	most_connected(the_collection);
	costs_for_route(the_collection);
}