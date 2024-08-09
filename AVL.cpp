#include <stdio.h>
#include <stdlib.h>


struct data{
	int key;
	int height;
	
	struct data *left;
	struct data *right;
}*root = NULL;


int getHeight(struct data *curr){
	if(curr == NULL){
		return 0;
	}else{
		return curr->height;
	}
}

int max(int a, int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}

struct data *rightRotation(struct data *C){
	struct data *B = C->left;
	struct data *x = B->right;
	
	B->right = C;
	C->left = x;
	
	C->height = max(getHeight(C->left), getHeight(C->right)) + 1;
	B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
	
	return B;
}

struct data *leftRotation(struct data *A){
	struct data *B = A->right;
	struct data *y = B->left;
	
	B->left = A;
	A->right = y;
	
	A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
	B->height = max(getHeight(B->left), getHeight(B->right)) + 1;
	
	return B;
}
int getBalancedFactor(struct data *curr){
	if(curr == NULL){
		return 0;
	}else{
		return getHeight(curr->left) - getHeight(curr->right);
	}
}

struct data *insert(struct data *curr, int key){
	if(curr == NULL){
		curr = (struct data *)malloc(sizeof(struct data));
		curr->right = curr->left = NULL;
		curr->key = key;
		curr->height = 1;
		return curr;
	}else if(curr->key > key){
		curr->left = insert(curr->left, key);
	}else if(curr->key < key){
		curr->right = insert(curr->right, key);
	}
		curr->height = max(getHeight(curr->left), getHeight(curr->right) + 1);
		
		int balancedFactor = getBalancedFactor(curr);
		
		if(balancedFactor > 1 && key < curr->left->key){
			return rightRotation(curr);
		}
		else if(balancedFactor < -1 && key > curr->right->key){
			return leftRotation(curr);
		}
		else if(balancedFactor > 1 && key > curr->left->key){
			return rightRotation(curr);
		}
		else if(balancedFactor < -1 && key < curr->right->key){
			return leftRotation(curr);
		}
	return curr;
}

void inOrder(struct data *curr){
	if(curr == NULL){
		return;
	}
		inOrder(curr->left);
		printf("%d -> ", curr->key);
		inOrder(curr->right);

}

struct data *deleteData(struct data *curr, int deleteKey){
	if(curr == NULL){
		return NULL;
	}
	else if(deleteKey < curr->key){
		curr->left = deleteData(curr->left, deleteKey);
	}else if(deleteKey > curr->key){
		curr->right = deleteData(curr->right, deleteKey);
	}else{
		
		if(curr->left == NULL || curr->right == NULL){
			struct data *temp = NULL;
			
			if(curr->left != NULL){
				temp= curr->left;
			}else{
				temp = curr->right;
			}
			
			if(temp == NULL){
				temp = curr;
				curr = NULL;
			}else{
				*curr = *temp;
			}
			
			free(temp);
			
		}else{
			struct data *temp = curr->left;
			while(temp->right != NULL){
				temp = temp->right;
			}	
			curr->key = temp->key;
			curr->left = deleteData(curr->left, curr->key);
		}
	}
	
	if(curr == NULL){
		return curr;
	}
	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	
	int balanceFactor = getBalancedFactor(curr);
	
	if(balanceFactor > 1 && getBalancedFactor(curr->left) >= 0){
		return rightRotation(curr);
	}else if(balanceFactor < -1 && getBalancedFactor(curr->right) <= 0){
		return leftRotation(curr);
	}else if(balanceFactor > 1 && getBalancedFactor(curr->left) < 0){
		curr->left = leftRotation(curr->left);
		return rightRotation(curr);
	}else if(balanceFactor < -1 && getBalancedFactor(curr->right) > 0){
		curr->right = rightRotation(curr->right);
		return leftRotation(curr);
	}
	return curr;
}

struct data *popAll(struct data *curr){
	if(curr == NULL){
		return NULL;
	}else{
		curr->left = popAll(curr->left);
		curr->right = popAll(curr->right);
		free(curr);
		return NULL;
	}
}

int main(){
	
	int key;
	int deleteKey;
	int choice = -1;
	
	do{
		inOrder(root);
		scanf("%d", &choice); getchar;
		switch(choice){
			case 1: {
				printf("Insert Data: ");
				scanf("%d", &key); getchar();
				root = insert(root, key);
				break;
			}
			case 2:{
				printf("Data to Delete: ");
				scanf("%d", &deleteKey); getchar();
				root = deleteData(root, deleteKey);
				break;
			}
		}
	}while(choice != 0);
	
	popAll(root);
	return 0;
}