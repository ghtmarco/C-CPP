#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int value;
    char nim[11];
    char name[51];
    struct data *left, *right, *parent;
}*root = NULL;

struct data* insert(struct data *curr, int insertVal, struct data *nodeParent){
    if(curr == NULL){
        curr = (struct data*)malloc(sizeof(struct data));
        curr->left = curr->right = NULL;
        curr->value = insertVal;
        curr->parent = nodeParent;
    }else{
        if(insertVal < curr->value){
            curr->left = insert(curr->left, insertVal, curr);
        }else if (insertVal > curr->value){
            curr->right = insert(curr->right, insertVal, curr);
        }
        
    }
    return curr;
}

struct data* search(struct data *curr, int searchVal){
    if(curr == NULL){
        return NULL;
    }else if(curr-> value == searchVal){
        return curr;
    }else if(searchVal < curr->value){
        return search(curr->left, searchVal);
    }else if(searchVal > curr->value){
        return search(curr->right, searchVal);
    }
}

struct data* deleteData(struct data *curr, int deleteVal){
    if(curr == NULL){
        return NULL;
    }else if(deleteVal < curr->value){
        curr->left = deleteData(curr->left, deleteVal);
    }else if(deleteVal > curr->value){
        curr->right = deleteData(curr->right, deleteVal);
    }else{
        if(curr->left == NULL || curr->right == NULL){
            struct data *temp = NULL;
            if(curr->left != NULL){
                temp = curr->left;
            }else if(curr->right != NULL){
                temp = curr->right;
            }
            if(temp == NULL){
                temp = curr;
                curr = NULL;
            }else{
                temp->parent = curr->parent;
                *curr = *temp;
            }
            free(temp);
        }else if(curr->left != NULL && curr->right != NULL){
            struct data *temp = curr->left;
            while(temp->right != NULL){
                temp = temp->right;
                curr->value = temp->value;
                curr->left = deleteData(curr->left, temp->value);
            }
        }
    }
    return curr;
}

struct data* popAll(struct data *curr){
    if(curr == NULL){
        return NULL;
    }else{
        curr-> left = popAll(curr->left);
        curr->right = popAll(curr->right);
        free(curr);
        return NULL;
    }
}

void inOrder(struct data *curr){
    if(curr == NULL){
    }else{
        if(curr->left != NULL){
            inOrder(curr->left);
        }
        if(curr != NULL){
            printf("%d ->", curr->value);
        }
        if(curr->right != NULL){
            inOrder(curr->right);
        }
    }
}

void postOrder(struct data *curr){
    if(curr == NULL){
        return;
    }else{
        if(curr->left != NULL){
            postOrder(curr->left);
        }
        if(curr->right != NULL){
            postOrder(curr->right);
        }
        if(curr != NULL){
            printf("%d", curr->value);
        }
    }
}

void preOrder(struct data *curr){
    if(curr == NULL){
        return;
    }else{
        if(curr != NULL){
            printf("%d", curr->value);
        }
        if(curr->left != NULL){
            preOrder(curr->left);
        }
        if(curr->right != NULL){
            preOrder(curr->right);
        }
    }
}

int main(){
    int pilihan;
    int insertVal;
    int deleteVal;
    int searchVal;

    do{
        puts("");
        puts("Data");
        puts("========");
        inOrder(root);
        puts("");
        puts("Menu");
        puts("1. Insert Data");
        puts("2. Search Data");
        puts("3. Delete Data");
        puts("0. Exit");
        printf(">> ");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:{
                printf("Insert Data: ");
                scanf("%d", &insertVal);
                root = insert(root, insertVal, NULL);
                break;
            }
            case 2:{
                printf(">> ");
                scanf("%d", &searchVal);
                struct data *temp = search(root, searchVal);
                if(temp == NULL){
                    printf("Data Not Found\n");
                }else{
                    printf("Data: %d\n", temp->value);
                    if(temp->left != NULL){
                        printf("Left Child: %d\n", temp->left->value);
                    }
                    if(temp->right != NULL){
                        printf("Right Child: %d\n", temp->right->value);
                    }
                    if(temp->parent != NULL){
                        printf("Parent: %d\n", temp->parent->value);
                    }
                    
                }
                getchar();
                break;
            }
            case 3:{
                printf(">> ");
                scanf("%d", &deleteVal);
                root = deleteData(root, deleteVal);
                break;
            }
        }
    }while(pilihan != 0);
    root = popAll(root);
    return 0;
}