#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{

    int value;
    struct data *left, *right, *parent;

}*root = NULL;

struct data* push(struct data *curr, int insertedValue, struct data *nodeParent){
    char pilihan[10];
    if(curr == NULL){
        curr = (struct data *) malloc(sizeof(struct data));
        curr->value = insertedValue;
        curr->left = curr->right = NULL;
        curr->parent = nodeParent;
    }else{

        printf("%d Want to insert L or R?\n", curr->value);
        scanf("%s", pilihan);
        getchar();

        if(strcmp(pilihan, "L") == 0){
            curr->left = push(curr->left, insertedValue, curr);
        }else if(strcmp(pilihan, "R") == 0){
            curr->right = push(curr->right, insertedValue, curr);
        }

    }

    return curr;
}
void preOrder(struct data *curr){
    if(curr != NULL){
        printf("%d -> ", curr-> value);
    }
    if(curr->left != NULL){
        preOrder(curr->left);
    }else if(curr->right != NULL){
        preOrder(curr->right);
    }
}

void inOrder(struct data *curr){
    if(curr != NULL){
        inOrder(curr->left);
    }
    if(curr->left != NULL){
        printf("%d -> ", curr-> value);
    }else if(curr->right != NULL){
        inOrder(curr->right);
    }
}

struct data* popAll(struct data *curr){
    if(curr == NULL){
        return NULL;   
    }
        curr->left = popAll(curr->left);
        curr->right = popAll(curr->right);
        free(curr);
        return NULL;
    

}

int main(){
    
    int insertedValue;
    int pilihan = -1;

    do{
        printf("1. Inserted Data\n");
        printf("2. View Data\n");
        printf("3. Exit\n");
        printf(">> ");
        scanf("%d", &pilihan);
        getchar();
        switch(pilihan){
            case 1:{
                printf("Masukan Angka: ");
                scanf("%d", &insertedValue);
                getchar();
                root = push(root, insertedValue, NULL);
                break;
            }
            case 2:{
                break;
            }
        }
    }while(pilihan != 3);

    return 0;
}