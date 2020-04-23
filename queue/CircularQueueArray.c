#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define data_type	int
#define length 		100
typedef struct queue{
    data_type data[length];
    int front;					// Used for delete operation
    int rear;					// Used for insert operation
}queue;

void init_queue(queue *q);

bool is_empty_queue(queue *q);
bool is_full_queue(queue *q);

void insert_queue(queue *q, data_type data);
data_type delete_queue(queue *q);

data_type get_queue_head(queue *q);
void display_queue(queue *q);


int main(void)
{
	int n, value;
	queue q;

	init_queue(&q);

	printf("-------------- Array For Circular Queue Test! --------------\n");
	printf("1 is_empty_queue()...\n");
	printf("2 is_full_queue()...\n");
	printf("3 insert_queue()...\n");
	printf("4 delete_queue()...\n");
	printf("5 get_queue_head()...\n");
	printf("6 display_queue()...\n");
	printf("-1 exit...\n");
	printf("---------------------------------------------------\n");

    while(1){
		printf("Please enter test option value: ");
		scanf("%d", &n);
    	switch (n){
    		case 1: printf("is empty queue?  %s\n\n", is_empty_queue(&q)?"true":"false"); break;
    		case 2: printf("is full queue?  %s\n\n", is_full_queue(&q)?"true":"false"); break;
    		case 3: 
    			printf("Enter the data inserted into the queue: ");
    			scanf("%d", &value);

    			if(is_full_queue(&q))
    				printf("Queue space is full\n\n");
    			else
     				insert_queue(&q, value); 
     			break;
    		case 4: 
    			if(is_empty_queue(&q))
    				printf("Queue space is empty\n\n");
    			else
    				printf("The deleted queue data is: %d\n\n", delete_queue(&q)); 
    			break;
    		case 5: 
    			if(is_empty_queue(&q))
    				printf("Queue space is empty\n\n");
    			else
    				printf("Get the head data of the queue is: %d\n\n", get_queue_head(&q)); 
    			break;
    		case 6: display_queue(&q); break;
    		case -1: return 0;
    		default: break;
    	}
    }
}

void init_queue(queue *q)
{
    q->front = 0;
    q->rear = 0;
    printf("Queue initialization completed\n\n");
}

bool is_empty_queue(queue *q)
{
    return (q->front == q->rear ? true:false);
}

bool is_full_queue(queue *q)
{
    return ((q->rear+1)%length == q->front ? true:false);
}

void insert_queue(queue *q, data_type data)
{
    if(!is_full_queue(q)){
        q->data[q->rear] = data;
        q->rear= (q->rear+1)%length;
        printf("Successfully inserted into the queue\n\n");
    }
}

data_type delete_queue(queue *q)
{
    if(!is_empty_queue(q)){
        if(q->front+1 == length){
            q->front = (q->front+1)%length;       //其实就是0
            return q->data[length-1];
        }else{
        	q->front++;
        	return q->data[q->front-1];
        }
    }
    return -1;
}

data_type get_queue_head(queue *q)
{
	return q->data[q->front];
}

void display_queue(queue *q)
{
    int i ;
    if(!is_empty_queue(q)){
        for(i=q->front;i!=q->rear;){
            printf("%d, ",q->data[i]);            
            i=(i+1)%length;
        }
        printf("\n");
    }
}
