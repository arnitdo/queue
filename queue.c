#include "queue.h"

queue* queue_init(){
	queue* q_ptr = malloc(sizeof(queue));
	q_ptr->first = malloc(QUEUE_SIZE * sizeof(TYPE));
	if (q_ptr->first == NULL){
		fprintf(stderr, "COULD NOT ALLOCATE QUEUE MEMORY FOR %I64u", QUEUE_SIZE * sizeof(TYPE));
		exit(1);
	}
	q_ptr->len = 0;
	return q_ptr;
}

void queue_insert(queue* q, TYPE  obj){
	if(q->len == QUEUE_SIZE){
		fprintf(stderr, "QUEUE FILLED WITH %i OBJECTS FROM %p TO %p! CONSIDER HAVING A LARGER QUEUE!", QUEUE_SIZE, q->first, (q->first + QUEUE_SIZE));
		exit(1);
	}
	*(q->first + q->len) = obj;
	q->len++;
}

TYPE queue_front(queue* q){
	if(q->len == 0){
		fprintf(stderr, "QUEUE AT %p IS EMPTY!", q->first);
		return 0;
	}
	TYPE obj = *(q->first);
	for (int i = 0; i < q->len - 1; i++){
		*(q->first + i) = *(q->first + i + 1);
	}
	*(q->first + q->len) = 0;
	q->len--;
	return obj;
}

void queue_delete(queue* q){
	free(q->first);
	q->first = 0;
	q->len = 0;
	free(q);
}

// SPECIAL

void queue_print(queue* q){
	if (queue_len(q) == 0){
		printf("QUEUE IS EMPTY!\n");
		return;
	}
	printf("FRONT OF QUEUE -> ");
	for (int i = 0; i < q->len; i++){
		// Assuming type is int
		printf("%i ", *(q->first + i));
	}
	printf("<- END OF QUEUE\n");
}

int queue_len(queue* q){
	return q->len;
}