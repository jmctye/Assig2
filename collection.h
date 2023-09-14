// KIT107 Assignment 2
/*
 * Specification for the Collection ADT
 * Author <<YOUR STUDENT ID AND NAME HERE>>
 * Version <<DATE>>
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#include "node.h"
#include "route.h"

typedef struct period_int *period_format;

struct collection_int {
	period_format first_period;
};

typedef struct collection_int *collection;

void init_collection(collection *lp);
period_format get_periods(collection l);
void set_periods(collection l, period_format f);
void add_route_to_collection(collection l, route r);
void route_changes(collection l);
void most_connected(collection l);
void costs_for_route(collection l);

#endif
