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
//delete
void delete_begin(void);
void delete_last(void);
//others
void display(void);
void search(void);

int main(void)
{
	int n;

	printf("-------------- Circular singly Lisked List Test! --------------\n");
	printf("0 inset_begin()...\n");
	printf("1 inset_last()...\n");
	printf("2 delete_begin()...\n");
	printf("3 delete_last()...\n");
	printf("4 display()...\n");
	printf("5 search()...\n");
	printf("-1 exit...\n");
	printf("---------------------------------------------------------------\n");

    while(1){
		printf("Please enter test option value: ");
		scanf("%d", &n);
    	switch (n){
    		case 0: inset_begin(); break;
    		case 1: inset_last(); break;
    		case 2: delete_begin(); break;
    		case 3: delete_last(); break;
    		case 4: display(); break;
    		case 5: search(); break;
    		case -1: return 0;
    		default: break;
    	}
    }
    return 0;
}

void inset_begin(void)
{
	struct node *ptr, *temp;
	int item;

	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("Out of memory space\n");
		return;
	}
	printf("Please enter the value(int) to be inserted in the begin: ");
	scanf("%d", &item);
	ptr->data = item;

	if(head == NULL){
		ptr->next = ptr;
		head = ptr;
	}else{
		temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		ptr->next = head;
		temp->next = ptr;
		head = ptr;
	}
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
		ptr->next = ptr;
		head = ptr;
	}else{
		temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = head;
	}
}

void delete_begin(void)
{
	struct node *temp, *temp1;
	if(head == NULL){
		printf("The linked list is empty and cannot be deleted\n\n");
		return;
	}else{
		if(head->next == head){
			free(head);
			head = NULL;
		}else{
			temp = head;
			temp1 = head;
			while(temp->next != head){
				temp = temp->next;
			}
			temp->next = temp1->next;
			head = temp1->next;
			free(temp1);
		}
		printf("Node deleted successfully\n\n");
	}
}

void delete_last(void)
{
	struct node *temp, *temp1;
	if(head == NULL){
		printf("The linked list is empty and cannot be deleted\n");
	}else{
		if(head->next == head){
			free(head);
			head = NULL;
		}else{
			temp = head;
			while(temp->next != head){
				temp1 = temp;
				temp = temp->next;
			}
			temp1->next = head;
			free(temp);
		}
		printf("Node deleted successfully\n\n");
	}
}

void display(void)
{
	int n=0;
	struct node *temp;
	
	printf("Display the entire linked list:\n");
	if(head == NULL){
		printf("Linked list is empty\n");
	}else{
		temp = head;
		while(temp->next != head){
			printf("-%02d- %d\n", n++, temp->data);
			temp = temp->next;
		}
		printf("-%02d- %d\n", n, temp->data);
		printf("\n");
	}
}

void search(void)
{
	struct node *temp;
	int item, loc=0, flag=0;
	printf("Please enter the value you want to search: ");
	scanf("%d",&item);
	if(head == NULL){
		printf("The linked list is empty!\n");
	}

	temp = head;
	while(temp->next != head){
		if(temp->data == item){
			printf("Find the target item at location %d\n", loc);
			flag = 1;
		}
		temp = temp->next;
		loc++;
	}
	if(temp->data == item){
		printf("Find the target item at location %d\n", loc);
		flag = 1;
	}
	
	if(flag == 0){
		printf("Linked list does not exist to find the data item\n");
	}else{
		printf("\n");
	}
}
