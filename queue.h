#ifndef S043_QUEUE
#define S043_QUEUE

#include <stdlib.h>
#include <stdio.h>

#define STRINGIFY(x) #x

#ifndef TYPE
#define TYPE int

#ifndef QUEUE_SIZE
#define QUEUE_SIZE 64

typedef struct
{
	TYPE* first;
	int len;
} queue;

queue* queue_init();

void queue_insert(queue*, TYPE);
TYPE queue_front(queue*);

void queue_delete(queue*);

// SPECIAL METHOD

void queue_print(queue*);

#endif
#endif
#endif