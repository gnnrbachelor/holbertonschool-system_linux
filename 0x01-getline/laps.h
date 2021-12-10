#ifndef LAPS_H
#define LAPS_H

#include <stdlib.h>
#include <stdio.h>


/**
 * car - Struct for Car
 * @id: ID
 * @lap_n: # of laps
 * @next: Pointer to next car
 *
 */

typedef struct car {
	int id;
	int lap_n;
	struct car *next;
} Car;

void race_state(int *id, size_t size);
void add_car(Car **head, int id);


#endif
