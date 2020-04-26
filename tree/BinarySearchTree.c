#include <stdio.h>
#include <stdlib.h>

typedef struct bst_node{
	int data;
	struct bst_node *left;
	struct bst_node *right;
}bst_tree;

typedef enum{
	dir_default=0,		// If no direction is specified, it is the root node
	dir_left,
	dir_right,
}direction;

bst_tree *create(int item);
void insert(bst_tree **root, int data);
void delete(bst_tree **root, int data);
void search(bst_tree *root, int des_val);
void preorder_traversal(bst_tree *root);
void inorder_traversal(bst_tree *root);
void postorder_traversal(bst_tree *root);
void layer_traversal(bst_tree *root);

bst_tree *find_max_node(bst_tree *root);
bst_tree *find_min_node(bst_tree *root);

int main(void)
{
	int data, option;
	bst_tree *root=NULL, *temp=NULL;

	insert(&root, 57);
	insert(&root, 18);
	insert(&root, 97);
	insert(&root, 31);
	insert(&root, 75);
	insert(&root, 24);
	insert(&root, 38);
	insert(&root, 28);
	insert(&root, 47);
	insert(&root, 80);

	printf("-------------- Binary Search Tree test --------------\n");
	printf("-1- insert\n");
	printf("-2- delete\n");
	printf("-3- search\n");
	printf("-4- preorder_traversal\n");
	printf("-5- inorder_traversal\n");
	printf("-6- postorder_traversal\n");
	printf("-7- layer_traversal\n");
	printf("-8- find_max_node\n");
	printf("-9- find_min_node\n");
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
				printf("Please enter the data to be deleted: ");
				scanf("%d", &data);
				delete(&root, data);
				break;
			case 3:
				printf("Please enter the data you need to search: ");
				scanf("%d", &data);	
				search(root, data);
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
			case 8:
				temp = find_max_node(root);
				if(temp != NULL)
					printf("max: %d\n", temp->data);
				break;
			case 9:
				temp = find_min_node(root);
				if(temp != NULL)
					printf("min: %d\n", temp->data);
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

void delete(bst_tree **root, int data)
{
	bst_tree *parent=NULL, *new_child, *temp;
	// Indicate the direction of deleting the node in the parent node
	direction parent_direction;

	temp = *root;
	while(temp != NULL){
		if(data < temp->data){
			parent = temp;
			parent_direction = dir_left;
			temp = temp->left;
		}else if(data == temp->data){
			printf("Find matching data\n");

			if(temp->left == NULL && temp->right == NULL){
				//set new child node
				new_child = NULL;

				if(parent_direction == dir_right)
					parent->right = new_child;
				else if(parent_direction == dir_left)
					parent->left = new_child;
				else
					*root = new_child;
			}else if(temp->left == NULL && temp->right != NULL){
				//set new child node
				new_child = temp->right;

				if(parent_direction == dir_right)
					parent->right = new_child;
				else if(parent_direction == dir_left)
					parent->left = new_child;
				else
					*root = new_child;
			}else if(temp->left != NULL && temp->right == NULL){
				//set new child node
				new_child = temp->left;

				if(parent_direction == dir_right)
					parent->right = new_child;
				else if(parent_direction == dir_left)
					parent->left = new_child;
				else
					*root = new_child;
			}else{
				//set new child node
				new_child = find_min_node(temp->right);
				if(temp)
				printf("new_child: %d\n", new_child->data);
				delete(&temp->right, new_child->data);

				new_child->right = temp->right;
				new_child->left = temp->left;

				if(parent_direction == dir_right)
					parent->right = new_child;
				else if(parent_direction == dir_left)
					parent->left = new_child;
				else
					*root = new_child;
			}
			return;
		}else{
			parent = temp;
			parent_direction = dir_right;
			temp = temp->right;
		}
	}
	printf("No matching data found\n");
}

void search(bst_tree *root, int des_val)
{
	// bst_tree *parent_node, child_node;
	bst_tree *temp;

	printf("des_val: %d\n", des_val);
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

void preorder_traversal(bst_tree *root)
{
	if(root == NULL){
		return;
	}else{
		printf("%d\n", root->data);
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}
}

void inorder_traversal(bst_tree *root)
{
	if(root == NULL){
		return;
	}else{
		inorder_traversal(root->left);
		printf("%d\n", root->data);
		inorder_traversal(root->right);
	}
}

void postorder_traversal(bst_tree *root)
{
	if(root == NULL){
		return;
	}else{
		printf("%d\n", root->data);
		postorder_traversal(root->right);
		postorder_traversal(root->left);
	}
}

// The breadth-first traversal of binary trees is also called traversal by layers. 
// The algorithm is implemented with the help of queues.
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

bst_tree *find_max_node(bst_tree *root)
{
	bst_tree *temp=NULL;
	if(root == NULL){
		printf("The binary tree is empty, there is no maximum node\n");
	}else{
		temp = root;
		while(temp->right != NULL){
			temp = temp->right;
		}
	}
	printf("find max node over!\n");
	return temp;
}

bst_tree *find_min_node(bst_tree *root)
{
	printf("fine min node\n");
	bst_tree *temp=NULL;
	if(root == NULL){
		printf("The binary tree is empty, there is no minimum node\n");
	}else{
		temp = root;
		while(temp->left != NULL){
			temp = temp->left;
		}
	}
	return temp;
}