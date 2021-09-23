#include "queue.c"

int main(){
	queue* my_queue = queue_init();
	for (int i = 0; i < 10; i++){
		printf("Enter number to insert : ");
		int obj;
		scanf(" %i", &obj);
		queue_insert(my_queue, obj);
	}
	printf("----- PRINTING QUEUE -----\n");
	queue_print(my_queue);

	queue_delete(my_queue);
	return 0;
}