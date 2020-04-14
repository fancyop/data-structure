#include <stdio.h>
#include <stdlib.h>

struct node
{
	int	data;
	struct node *next;
};

struct node	*head;

//insert
void inset_begin(void);
void inset_last(void);
void inset_random(void);
//delete
void delete_begin(void);
void delete_last(void);
void delete_random(void);
//others
void display(void);
void search(void);

int main(void)
{
	int n;

	printf("-------------- Singly Lisked List Test! --------------\n");
	printf("0 inset_begin()...\n");
	printf("1 inset_last()...\n");
	printf("2 inset_random()...\n");
	printf("3 delete_begin()...\n");
	printf("4 delete_last()...\n");
	printf("5 delete_random()...\n");
	printf("6 display()...\n");
	printf("7 search()...\n");
	printf("-1 exit...\n");
	printf("------------------------------------------------------\n");

    while(1){
		printf("Please enter test option value: ");
		scanf("%d", &n);
    	switch (n){
    		case 0: inset_begin(); break;
    		case 1: inset_last(); break;
    		case 2: inset_random(); break;
    		case 3: delete_begin(); break;
    		case 4: delete_last(); break;
    		case 5: delete_random(); break;
    		case 6: display(); break;
    		case 7: search(); break;
    		case -1: return 0;
    		default: break;
    	}
    }
    return 0;
}

void inset_begin(void)
{
	struct node *ptr;
	int item;

	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("Out of memory space\n");
		return;
	}
	printf("Please enter the value(int) to be inserted in the begin: ");
	scanf("%d", &item);
	ptr->data = item;

	ptr->next = head;
	head = ptr;
	printf("Node inserted successfully\n\n");
}

void inset_last(void)
{
	struct node *ptr, *temp;
	int item;

	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("Out of memory space\n");
		return;
	}

	printf("Please enter the value(int) to be inserted in the last: ");
	scanf("%d", &item);
	ptr->data = item;
	if(head == NULL){
		ptr->next = NULL;
		head = ptr;
	}else{
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = NULL;
	}
	printf("Node inserted successfully\n\n");
}

void inset_random(void)
{
	struct node *ptr, *temp;
	int item, loc, i;

	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("Out of memory space\n");
		return;
	}

	printf("Please enter the value(int) to random insert: ");
	scanf("%d", &item);
	ptr->data = item;
	printf("Enter the location(>=0) of any node to insert: ");
	scanf("%d", &loc);

	if(head == NULL){	// loc can only be 0
		if(loc == 0){
			ptr->next = head;
			head = ptr;
		}else{
			printf("No node can be inserted here\n\n");
			return;
		}
	}else{
		if(loc == 0){	// Need to change head
			ptr->next = head;
			head = ptr;
		}else{
			temp = head;
			for(i = 1; i < loc; i++){
				temp = temp->next;
				if(temp == NULL){
					printf("No node can be inserted here\n\n");
					return;
				}
			}
			ptr->next = temp->next;
			temp->next = ptr;
		}
	}
	printf("Node inserted successfully\n\n");
}

void delete_begin(void)
{
	struct node *temp;
	if(head == NULL){
		printf("The linked list is empty and cannot be deleted\n\n");
		return;
	}
	temp = head->next;
	free(head);
	head = temp;
	printf("Node deleted successfully\n\n");
}

void delete_last(void)
{
	struct node *temp, *temp1;
	if(head == NULL){
		printf("The linked list is empty and cannot be deleted\n");
	}else if(head->next == NULL){
		head = NULL;
		free(head);
		printf("Node deleted successfully\n\n");
	}else{
		temp = head;
		while(temp->next != NULL){
			temp1 = temp;
			temp = temp->next;
		}
		temp1->next = NULL;
		free(temp);
		printf("Node deleted successfully\n\n");
	}
}

void delete_random(void)
{
	struct node *temp, *temp1;
	int loc, i;

	if(head == NULL){
		printf("The linked list is empty and cannot be deleted\n");
	}else{
		printf("Please enter the node location(>=1) you want to delete: ");
		scanf("%d", &loc);
		if(loc == 0){
			temp = head->next;
			free(head);
			head = temp;
			printf("Node deleted successfully\n\n");
		}else{
			temp = head;
			for(i = 0; i < loc; i++){
				if(temp->next == NULL){
					printf("The location node cannot be deleted here\n");
					return;
				}
				temp1 = temp;
				temp = temp->next;
			}
			temp1->next = temp->next;
			free(temp);
			printf("Node deleted successfully\n\n");
		}
	}
}

void display(void)
{
	int n=0;
	struct node *temp;

	printf("Display the entire linked list:\n");
	if(head == NULL){
		printf("Linked list is empty\n");
	}
	temp = head;
	while(temp != NULL){
		printf("-%02d- %d\n", n++, temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void search(void)
{
	struct node *temp;
	int item, loc, flag=0;
	printf("Please enter the value you want to search: ");
	scanf("%d",&item);
	if(head == NULL){
		printf("The linked list is empty!\n");
		return;
	}
	temp = head;
	loc = 0;
	while(temp != NULL){
		if(temp->data == item){
			printf("Find the target item at location %d\n", loc);
			flag = 1;
		}
		temp = temp->next;
		loc++;
	}
	if(flag == 0){
		printf("Linked list does not exist to find the data item\n");
	}else{
		printf("\n");
	}
}