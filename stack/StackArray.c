#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];	// stack space 
int top = -1;			// top position of stack

void push(void);		// push stack
void pop(void);			// pop stack
void peek(void);		// observe the value pointed by top
void display(void);		// display all values in the stack

int main(void)
{
	int n;

	printf("-------------- Array For Stack Test! --------------\n");
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
	int value;
	if((top+1) == MAX_SIZE)
		printf("[PUSH] Overflow\n");
	else{
		printf("Enter push value(int): ");
		scanf("%d", &value);
		top++;
		stack[top] = value;
	}
	printf("\n");
}

void pop(void)
{
	int value;
	if(top == -1)
		printf("[POP] Underflow\n");
	else{
		value = stack[top];
		top--;
		printf("pop value is: %d\n", value);
	}
	printf("\n");
}

void peek(void)
{
	int value;
	if(top == -1)
		printf("[PEEK] Underflow\n");
	else{
		value = stack[top];
		printf("peek value is: %d\n", value);
	}
	printf("\n");
}

void display(void)
{
	int i, temp;
	if(top == -1){
		printf("stack is empty\n");
	}else{
		temp = top;
		for(i = 0; i <= temp; i++){
			printf("-%d- %d\n", i, stack[i]);
		}
	}
	printf("\n");
}