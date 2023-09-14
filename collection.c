// KIT107 Assignment 2
/*
 * Implementation for the Collection ADT
 * Author <<YOUR STUDENT ID AND NAME HERE>>
 * Version <<DATE>>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "collection.h"

/* Types */

struct collection_int {
	period_format first_period;
};

/* Functions */

/*
 * 'Constructor' for collection
 * Param lp pointer to collection being constructed
 */
void init_collection(collection *lp)
{
	*lp = (collection)malloc(sizeof(struct collection_int));
	(*lp)->first_period = NULL;
}

/*
 * Getter for periods
 * Param c collection variable to examine
 * Return first_period field
 */
period_format get_periods(collection l)
{
	return l->first_period;
}

/*
 * Setter for periods
 * Param c collection variable to update
 * Param f value to be placed into the collection's first_period field
 */
void set_periods(collection l, period_format f)
{
	l->first_period = f;
}

/*
 * Doer function to add a route to the collection
 * Param l collection variable to update
 * Param r value to be added to the collection in ascending order of year and month
 */
void add_route_to_collection(collection l, route r)
{
	period_format current_period = get_periods(l);

	// If the collection is empty, create a new period and add the route to it.
	if (current_period == NULL)
	{
		current_period = (period_format)malloc(sizeof(struct period_int));
		init_period(current_period);
		add_route_to_period(current_period, r);
		set_periods(l, current_period);
	}

	// If the current period is not the correct period, find the correct period and add the route to it.
	else if (get_year(r) != get_year(current_period) || get_month(r) != get_month(current_period))
	{
		while (current_period->next != NULL && (get_year(r) > get_year(current_period->next) || (get_year(r) == get_year(current_period->next) && get_month(r) > get_month(current_period->next))))
		{
			current_period = current_period->next;
		}

		if (get_year(r) > get_year(current_period) || (get_year(r) == get_year(current_period) && get_month(r) > get_month(current_period)))
		{
			period_format new_period = (period_format)malloc(sizeof(struct period_int));
			init_period(new_period);
			add_route_to_period(new_period, r);
			current_period->next = new_period;
		}
		else
		{
			add_route_to_period(current_period, r);
		}
	}

	// If the current period is the correct period, simply add the route to it.
	else
	{
		add_route_to_period(current_period, r);
	}
}

/*
 * Utility doer function to constructively convert a string to lower case returning the result
 * Param s1 the string to convert
 * Return s2 the converted string (without altering the parameter)
 */
char *to_lower(char *s1)
{
	char *s2;
	int l;

	// create a new string as a copy of the given string with lower-case letters
	l = (int)strlen(s1);
	s2 = (char *)malloc((l+1) * sizeof(char));
	for (int i = 0; i < l; i++)
	{
		s2[i] = tolower(s1[i]);
	}
	s2[l] = '\0';	// terminate the new string

	// return the lower-case copy of the string
	return s2;
}

/*
 * Doer function to display how the number of routes has changed in
