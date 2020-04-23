#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define data_type	unsigned int
#define MAX_SIZE	10

typedef struct node{
	data_type	data;
	struct node *next;
}queue;

bool is_empty_queue(queue *head);
bool is_full_queue(queue *head);

void insert_queue(queue **head, data_type value);
data_type delete_queue(queue **head);
data_type get_queue_head(queue *head);

void display_queue(queue *head);

int main(void)
{
	int n, value;
	queue *q=NULL;

	printf("-------------- Linked-list For Queue Test! --------------\n");
	printf("1 is_empty_queue()...\n");
	printf("2 is_full_queue()...\n");
	printf("3 insert_queue()...\n");
	printf("4 delete_queue()...\n");
	printf("5 get_queue_head()...\n");
	printf("6 display_queue()...\n");
	printf("-1 exit...\n");
	printf("---------------------------------------------------------\n");

    while(1){
		printf("Please enter test option value: ");
		scanf("%d", &n);
    	switch (n){
    		case 1: printf("is empty queue?  %s\n\n", is_empty_queue(q)?"true":"false"); break;
    		case 2: printf("is full queue?  %s\n\n", is_full_queue(q)?"true":"false"); break;
    		case 3: 
    			printf("Enter the data inserted into the queue: ");
    			scanf("%d", &value);
    			insert_queue(&q, value); 
				break;
    		case 4: delete_queue(&q); break;
    		case 5: get_queue_head(q); break;
    		case 6: display_queue(q); break;
    		case -1: return 0;
    		default: break;
    	}
    }
}

bool is_empty_queue(queue *head)
{
	return (head == NULL)?true:false;
}

bool is_full_queue(queue *head)
{
	queue *temp;
	int count=0;

	if(head == NULL){
		return false;
	}else{
		temp = head;
		while(temp != NULL){
			count++;
			temp = temp->next;
		}
		return (count==MAX_SIZE)?true:false;
	}
}

void insert_queue(queue **head, data_type value)
{
	queue *ptr, *temp;
	int count=0;

	ptr = (queue *)malloc(sizeof(queue));
	if(ptr == NULL){
		printf("Out of memory space\n");
		return;
	}
	ptr->data = value;

	if((*head) == NULL){
		ptr->next = NULL;
		(*head) = ptr;
	}else{
		temp = (*head);
		count++;
		while(temp->next != NULL){
			count++;
			temp = temp->next;
		}
		if(count == MAX_SIZE){
			printf("The queue is full and data cannot be inserted\n\n");
			return;
		}else{
			temp->next = ptr;
			ptr->next = NULL;			
		}
	}
	printf("The element successfully inserted into the queue is: %d\n\n", value);
}

data_type delete_queue(queue **head)
{
	queue *temp;
	data_type value;

	if(is_empty_queue((*head))){
		printf("The linked list is empty and cannot be deleted\n\n");
		return -1;
	}
	value = (*head)->data;
	temp = (*head)->next;
	free((*head));
	(*head) = temp;
	printf("The deleted queue head element is: %d\n\n", value);
	return value;
}

data_type get_queue_head(queue *head)
{
	data_type value;

	if(is_empty_queue(head)){
		printf("Queue space is empty\n\n");
		return -1;
	}
	value = head->data;
	printf("The head element of the queue is: %d\n\n", value);
	return value;
}

void display_queue(queue *head)
{
	queue *temp;

	printf("Display the entire queue:\n");
	if(is_empty_queue(head)){
		printf("Queue space is empty\n");
	}else{
		temp = head;
		while(temp != NULL){
			printf("%d\n", temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}