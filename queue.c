#include <stdlib.h>
#include <stdio.h>

// Queue size must be a compile-time constant
#ifndef QUEUE_SIZE
#define QUEUE_SIZE 64
#endif

typedef struct
{
	int* first;
	int len;
} queue;

// Fwd declaration

queue* queue_init();
void queue_insert(queue*, int);
int queue_front(queue*);
void queue_delete(queue*);
void queue_print(queue*);
int queue_len(queue*);

// Implementation of prototypes

queue* queue_init(){
	queue* q_ptr = malloc(sizeof(queue));
	q_ptr->first = malloc(QUEUE_SIZE * sizeof(int));
	if (q_ptr->first == NULL){
		fprintf(stderr, "COULD NOT ALLOCATE QUEUE MEMORY FOR %I64u\n", QUEUE_SIZE * sizeof(int));
		exit(1);
	}
	q_ptr->len = 0;
	return q_ptr;
}

void queue_insert(queue* q, int  obj){
	if(q->len == QUEUE_SIZE){
		fprintf(stderr, "QUEUE FILLED WITH %i OBJECTS FROM %p TO %p! CONSIDER HAVING A LARGER QUEUE!\n", QUEUE_SIZE, q->first, (q->first + QUEUE_SIZE));
		exit(1);
	}
	*(q->first + q->len) = obj;
	q->len++;
}

int queue_front(queue* q){
	if(q->len == 0){
		fprintf(stderr, "QUEUE IS EMPTY!\n");
		return 0;
	}
	int obj = *(q->first);
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

// Menu driven in main()

int main(){
	queue* my_queue = queue_init();
	int input = 0;
	printf("Queue Implementation by S043 Arnav Deo\n");
	do {	
		printf("\nSelect Queue Operation - \n");
		printf("\t1 : Insert\n");
		printf("\t2 : Front\n");
		printf("\t3 : Length\n");
		printf("\t4 : Print\n");
		printf("\n\t0 : Exit\n");
		printf("\nSelect > ");
		scanf(" %i", &input);
		switch (input){
			case 0:{
				exit(0);
			}	
			case 1:{
				int obj;
				printf("Enter number to insert : ");
				scanf(" %i", &obj);
				queue_insert(my_queue, obj);
				break;
			}	
			case 2:{
				if (queue_len(my_queue)){
					int front = queue_front(my_queue);
					printf("Front number is : %i\n", front);
				} else {
					fprintf(stderr, "QUEUE IS EMPTY!\n");
				}
				break;
			}	
			case 3:{
				int len = queue_len(my_queue);
				printf("Length of queue is : %i\n", len);
				break;
			}	
			case 4:{
				queue_print(my_queue);
				break;
			}
			default:{
				break;
			}					
		}
	} while (input != 0);
	return 0;
}
