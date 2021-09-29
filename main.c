#include "queue.c"

int main(){
	queue* my_queue = queue_init();
	int input = 0;
	do {	
		printf("Queue Implementation by S043 Arnav Deo\n");
		printf("Select Queue Operation - \n");
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
				int front = queue_front(my_queue);
				printf("Front number is : %i\n", front);
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