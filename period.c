// KIT107 Assignment 2
/*
 * Implementation for the Period ADT
 * Author <<YOUR STUDENT ID AND NAME HERE>>
 * Version <<DATE>>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "period.h"

/* Types */

struct period_int {
	int year;
	int month;
	route_format first_route;
	struct period_int *next;
};

/* Functions */

/*
 * 'Constructor' for period
 * Param pp pointer to period being constructed
 */
void init_period(period_format *pp)
{
	*pp = (period_format)malloc(sizeof(struct period_int));
	(*pp)->year = 0;
	(*pp)->month = 0;
	(*pp)->first_route = NULL;
	(*pp)->next = NULL;
}

/*
 * Getter for routes
 * Param p period variable to examine
 * Return first_route field
 */
route_format get_routes(period_format p)
{
	return p->first_route;
}

/*
 * Setter for routes
 * Param p period variable to update
 * Param f value to be placed into the period's first_route field
 */
void set_routes(period_format p, route_format f)
{
	p->first_route = f;
}

/*
 * Doer function to add a route to the period
 * Param p period variable to update
 * Param r value to be added to the period in alphabetical order
 */
void add_route_to_period(period_format p, route r)
{
	route_format current_route = get_routes(p);
	route_format previous_route = NULL;

	// If the period is empty, simply add the route to it.
	if (current_route == NULL)
	{
		set_routes(p, r);
	}

	// Otherwise, find the correct position to insert the route into the period.
	else
	{
		while (current_route != NULL && strcmp(to_lower(get_description(r)), to_lower(get_description(current_route)))) > 0)
		{
			previous_route = current_route;
			current_route = current_route->next;
		}

		if (previous_route == NULL)
		{
			// The route is the first route in the period.
			set_routes(p, r);
			r->next = current_route;
		}
		else
		{
			// The route is inserted into the middle or end of the period.
			previous_route->next = r;
			r->next = current_route;
		}
	}
}
