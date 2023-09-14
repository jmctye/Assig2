// KIT107 Assignment 2
/*
 * Implementation for the Route ADT
 * Author Julian Dermoudy
 * Version 23/8/2023
 *
 * THIS FILE IS COMPLETE
 */

#include <stdio.h>
#include <stdlib.h>
#include "route.h"


/* Types */

struct route_int {
	int year;
	int month;
	char *port1;
	char *port2;
	char *description;
	double price_then;
	double price_now;
};


/* Functions*/

/*
* 'Constructor' for route
* Param rp pointer to route being constructed
* Param y year
* Param m month
* Param p1 port 1
* Param p2 port 2
* Param d route description
* Param c route rost originally
* Param r route rost in today's (real) dollars
*/
void init_route(route *rp, int y, int m, char *p1, char *p2, char *d, double c, double r)
{
	// create space for the route
	*rp = (route)malloc(sizeof(struct route_int));

	// update the fields
	(*rp)->year = y;
	(*rp)->month = m;
	(*rp)->port1 = p1;
	(*rp)->port2 = p2;
	(*rp)->description = d;
	(*rp)->price_then = c;
	(*rp)->price_now = r;
}

/*
* Getter for year
* Param r route variable to examine
* Return year field
*/
int get_year(route r)
{
	return (r->year);
}

/*
* Getter for month
* Param r route variable to examine
* Return month field
*/
int get_month(route r)
{
	return (r->month);
}

/*
* Getter for port1
* Param r route variable to examine
* Return port1 field
*/
char *get_port1(route r)
{
	return (r->port1);
}

/*
* Getter for port2
* Param r route variable to examine
* Return port2 field
*/
char *get_port2(route r)
{
	return (r->port2);
}

/*
* Getter for description
* Param r route variable to examine
* Return description field
*/
char *get_description(route r)
{
	return (r->description);
}

/*
* Getter for price_then
* Param r route variable to examine
* Return price_then field
*/
double get_price_then(route r)
{
	return (r->price_then);
}

/*
* Getter for price_now
* Param r route variable to examine
* Return price_now field
*/
double get_price_now(route r)
{
	return (r->price_now);
}

/*
* Setter for year
* Param r route variable to update
* Param y value to be placed into the route's year field
*/
void set_year(route r, int y)
{
	r->year = y;
}

/*
* Setter for month
* Param r route variable to update
* Param m value to be placed into the route's month field
*/
void set_month(route r, int m)
{
	r->month = m;
}

/*
* Setter for port1
* Param r route variable to update
* Param p value to be placed into the route's port1 field
*/
void set_port1(route r, char *p)
{
	r->port1 = p;
}

/*
* Setter for port2
* Param r route variable to update
* Param p value to be placed into the route's port2 field
*/
void set_port2(route r, char *p)
{
	r->port2 = p;
}

/*
* Setter for description
* Param r route variable to update
* Param d value to be placed into the route's description field
*/
void set_description(route r, char *d)
{
	r->description = d;
}

/*
* Setter for price_then
* Param r route variable to update
* Param c value to be placed into the route's price_then field
*/
void set_price_then(route r, double c)
{
	r->price_then = c;
}

/*
* Setter for price_now
* Param r route variable to update
* Param v value to be placed into the route's price_now field
*/
void set_price_now(route r, double v)
{
	r->price_now = v;
}

/*
* Display function
* Param r route to be displayed
* Return r formatted as a string
*/
char *to_string(route r)
{
	const char *MONTHS[12] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };

	char *s=(char *)malloc(200*sizeof(char));
	
	sprintf(s, "%s -- %s %d costing $%0.2lf then and $%0.2lf now.", r->description, 
		MONTHS[r->month-1], r->year, r->price_then, r->price_now);
	
	return s;
}
