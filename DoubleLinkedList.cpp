#include <stdio.h>
#include <stdlib.h>


struct data{

int value;
struct data *next;
struct data *prev;

}*head = NULL, *tail = NULL, *curr;

void pushHead(int Value){

    curr = (struct data*)malloc(sizeof(struct data));
    curr -> value = Value;
    curr -> next = curr -> prev = NULL;

    if(head == NULL){
        head = tail = curr;
    }else{
        head->prev = curr;
        curr->next = head;
        head = curr;
    }
    head->prev = tail->next = NULL;

}

void pushTail(int Value){

    curr = (struct data*)malloc(sizeof(struct data));
    curr -> value = Value;
    curr -> next = curr -> prev = NULL;

    if(head == NULL){
        head = tail = curr;
    }else{
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
    head->prev = tail->next = NULL;

}

void pushMid(int Value){

    curr = (struct data*)malloc(sizeof(struct data));
    curr -> value = Value;
    curr -> next = curr -> prev = NULL;

    if(head == NULL){
        head = tail = curr;
    }else{
        if(Value < head->value){
            head->prev = curr;
            curr->next = head;
            head = curr;

        }else if(Value > tail->value){
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }else{
            struct data *temp = head;
            while(temp->next->value < Value){
                temp = temp->next;
            }

            curr->next = temp->next;
            curr->prev = temp;
            temp->next->prev = curr;
            temp->next = curr;
        }
    }
    head->prev = tail->next = NULL;

}
 
void popHead(){
    curr = head;
    if(curr != NULL){
        head = head->next;
        free(curr);

        if(head == NULL){
            head = tail = NULL;
        }
    }
}

void popTail(){
    curr = tail;
    if(curr != NULL){
        tail = tail->prev;
        free(curr);

        if(head == NULL){
            head = tail = NULL;
        }
    }
}

void popMid(int del){
    if(head != NULL){
    if(head->value == del){
        curr = head;
        head = head -> next;
        free(curr);
        if(head == NULL){
            head = tail = NULL;
        }
    }else if(tail->value == del){
        curr = tail;
        tail = tail->prev;
        free(curr);
        if(tail == NULL){
            head = tail = NULL;
        }

    }else{

        curr = head;
        while(curr != NULL && curr->value != del){
            curr = curr->next;
        }
        if(curr == NULL){
            printf("Data Not Found!\n");
        }else{
            struct data *temp = curr->prev;

            temp->next = curr->next;
            temp->next->prev = curr;
            curr->next = curr->prev = NULL;
            free(curr);
        }

        }
    }

}

void print(){
    curr = head;
    while(curr != NULL){
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void popAll(){

    curr = head;
    while(curr != NULL){
        head = head->next;
        free(curr);
        curr = head;
    }
    head = tail = NULL;
}


int main(){
    
    int pilihan, Value, del;
    
    do{
    printf("1. Insert Data\n");
    printf("2. Delete Data\n");
    printf("3. Exit\n");
    printf(">> ");
    print();
    scanf("%d", &pilihan);

    switch(pilihan){
        case 1:
            printf("Masukan Data : ");
            scanf("%d", &Value);
            pushHead(Value);
            break;
        case 2:
            printf("Delete Data : ");
            scanf("%d", &del);
            popMid(del);
            break;

        case 3:
            popAll();
            break;
        }
    }while(pilihan != 3);

    popAll();
    return 0;
}
