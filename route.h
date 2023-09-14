// KIT107 Assignment 2
/*
 * Specification for the Route ADT
 * Author Julian Dermoudy
 * Version 23/8/2023
 *
 * THIS FILE IS COMPLETE
 */

#ifndef ROUTE_H
#define ROUTE_H

struct route_int;
typedef struct route_int *route;

void init_route(route *rp, int y, int m, char *p1, char *p2, char *d, double c, double r);
int get_year(route r);
int get_month(route r);
char *get_port1(route r);
char *get_port2(route r);
char *get_description(route r);
double get_price_then(route r);
double get_price_now(route r);
void set_year(route r, int y);
void set_month(route r, int m);
void set_port1(route r, char *p);
void set_port2(route r, char *p);
void set_description(route r, char *d);
void set_price_then(route r, double c);
void set_price_now(route r, double v);
char *to_string(route c);

#endif