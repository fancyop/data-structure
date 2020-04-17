#include <stdio.h>
#include <stdlib.h>

struct node
{
	int	data;
	struct node *next;
};
struct node	*head;
#define MAX_SIZE 10
int stacks_num = 0;		// number of stacks

void push(void);		// push stack
void pop(void);			// pop stack
void peek(void);		// observe the value pointed by top
void display(void);		// display all values in the stack

int main(void)
{
	int n;

	printf("-------------- Linked-list For Stack Test! --------------\n");
	printf("0 push()...\n");
	printf("1 pop()...\n");
	printf("2 peek()...\n");
	printf("3 display()...\n");
	printf("-1 exit...\n");
	printf("---------------------------------------------------\n");

    while(1){
		printf("Please enter test option value: ");
		scanf("%d", &n);
    	switch (n){
    		case 0: push(); break;
    		case 1: pop(); break;
    		case 2: peek(); break;
    		case 3: display(); break;
    		case -1: return 0;
    		default: break;
    	}
    }
    return 0;
}


void push(void)
{
	struct node *ptr;
	int value;

	if(stacks_num == MAX_SIZE)
		printf("[PUSH] Overflow\n");
	else{
		ptr = (struct node *)malloc(sizeof(struct node));
		if(ptr == NULL){
			printf("Out of memory space\n");
			return;
		}
		printf("Enter push value(int): ");
		scanf("%d", &value);
		ptr->data = value;

		ptr->next = head;
		head = ptr;
		printf("Item pushed\n\n");
		stacks_num++;
	}
}

void pop(void)
{
	struct node *temp;
	if(head == NULL){
		printf("[POP] Underflow\n\n");
		return;
	}
	printf("pop value is: %d\n\n", head->data);
	temp = head->next;
	free(head);
	head = temp;
	stacks_num--;
}

void peek(void)
{
	if(head == NULL){
		printf("[PEEK] Underflow\n\n");
		return;
	}
	printf("peek value is: %d\n\n", head->data);
}

void display(void)
{
	int count = stacks_num;
	struct node *temp;

	printf("Display all values in the stack:\n");
	if(head == NULL){
		printf("Stack is empty\n");
	}else{
		temp = head;
		printf("stacks_num: %d\n", count);
		while(temp != NULL){
			printf("-%02d- %d\n", count--, temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}