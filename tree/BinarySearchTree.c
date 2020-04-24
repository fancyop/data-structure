#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node{
	int data;
	struct bst_node *left;
	struct bst_node *right;
}bst_tree;

bst_tree *create(int item);
void insert(bst_tree **root, int data);
void delete(bst_tree *root);
void serach(bst_tree *root, int des_val);
void preorder_traversal(bst_tree *root);
void inorder_traversal(bst_tree *root);
void postorder_traversal(bst_tree *root);
void layer_traversal(bst_tree *root);

int main(void)
{
	int data, option;
	bst_tree *root=NULL;

	printf("-------------- Binary Search Tree test --------------\n");
	printf("-1- insert\n");
	printf("-2- delete\n");
	printf("-3- serach\n");
	printf("-4- preorder_traversal\n");
	printf("-5- inorder_traversal\n");
	printf("-6- postorder_traversal\n");
	printf("-7- layer_traversal\n");
	printf("-100- exit\n");
	while(1){
		printf("Enter test options according to the prompt above: ");
		scanf("%d", &option);
		switch(option){
			case 1: 
				printf("Please enter data: ");
				scanf("%d", &data);	
				insert(&root, data);
				break;
			case 2: 
				break;
			case 3: 
				printf("Please enter the data you need to find: ");
				scanf("%d", &data);	
				serach(root, data);
				printf("\n");
				break;
			case 4: 
				preorder_traversal(root);
				break;
			case 5: 
				inorder_traversal(root);
				break;
			case 6: 
				postorder_traversal(root);
				break;
			case 7: 
				layer_traversal(root);
				break;
			case 100: 
				return -1;
			default: 
				break;
		}
	}
	return 0;
}

bst_tree *create(int item)
{
	bst_tree *new_node;

	new_node = malloc(sizeof(bst_tree));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = item;
	return new_node;
}

void insert(bst_tree **root, int data)
{
	int temp;

	if((*root) == NULL){
		(*root) = create(data);
	}else{
		temp = (*root)->data;
		// printf("%d\n", temp);
		if(data > temp)
			insert(&((*root)->right), data);
		else
			insert(&((*root)->left), data);
	}
}

void delete(bst_tree *root)
{

}

void serach(bst_tree *root, int des_val)
{
	// bst_tree *parent_node, child_node;
	bst_tree *temp;

	printf("des_val: %d\n", des_val);
	if(root == NULL){
		printf("The binary tree is empty\n");
	}else{
		temp = root;
		while(temp != NULL){
			if(des_val < temp->data){
				temp = temp->left;
			}else if(des_val == temp->data){
				printf("Find matching data\n");
				return;
			}else{
				temp = temp->right;
			}
		}
		printf("No matching data found\n");
	}
}

void preorder_traversal(bst_tree *root)
{
	if(root == NULL){
		printf("The binary tree is empty\n");
		return;
	}else{
		printf("%d, \n", root->data);
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}
}

void inorder_traversal(bst_tree *root)
{
	if(root == NULL){
		printf("The binary tree is empty\n");
		return;
	}else{
		inorder_traversal(root->left);
		printf("%d, \n", root->data);
		inorder_traversal(root->right);
	}
}

void postorder_traversal(bst_tree *root)
{
	if(root == NULL){
		printf("The binary tree is empty\n");
		return;
	}else{
		printf("%d, \n", root->data);
		postorder_traversal(root->right);
		postorder_traversal(root->left);
	}
}

//The breadth-first traversal of binary trees is also called traversal by layers. 
//The algorithm is implemented with the help of queues.
void layer_traversal(bst_tree *root)
{
	bst_tree **bst_node_array;
	int head=0, tail=0;
	bst_tree *temp;

	if(root == NULL){
		printf("The binary tree is empty\n");
		return;
	}else{
		tail++;
		bst_node_array = malloc(sizeof(bst_tree*) * 1);
		bst_node_array[tail-1] = root;
		while(tail > head){
			// printf("temp: %d\n", temp);
			temp = bst_node_array[head];

			printf("%d, ", temp->data);

			if(temp->left != NULL){
				tail++;
				bst_node_array = realloc(bst_node_array, sizeof(bst_tree*) * tail);
				bst_node_array[tail-1] = temp->left;
			}
			if(temp->right != NULL){
				tail++;
				bst_node_array = realloc(bst_node_array, sizeof(bst_tree*) * tail);
				bst_node_array[tail-1] = temp->right;
			}

			head++;
		}
		printf("\n\n");
	}
}
