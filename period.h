// KIT107 Assignment 2
/*
 * Specification for the Period ADT
 * Author <<YOUR STUDENT ID AND NAME HERE>>
 * Version <<DATE>>
 */

#ifndef PERIOD_H
#define PERIOD_H

#include "node.h"
#include "route.h"

typedef struct route *route_format;

struct period_int {
	int year;
	int month;
	route_format first_route;
	struct period_int *next;
};

typedef struct period_int *period_format;

void init_period(period_format *pp);
route_format get_routes(period_format p);
void set_routes(period_format p, route_format f);
void add_route_to_period(period_format p, route r);

#endif

