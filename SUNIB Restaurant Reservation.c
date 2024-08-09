#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char status[10];
    char name[50];
    struct data *next;
    struct data *prev;
}*head = NULL, *tail = NULL, *curr;


struct data *addCustomer(char status[], char name[]){
    curr = (struct data *)malloc(sizeof(struct data));
    strcpy(curr->status, status);
    strcpy(curr->name, name);
    curr->next = curr->prev = NULL;
    if(head == NULL){
        head = tail = curr;
    }else{
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
    return curr;
}

void serveOne(){
    curr = head;
    if(head == NULL){
        return;
    }
    else if(head == tail){
        head = tail = NULL;
        printf("Attention! %s is being served at %s table\n", curr->name, curr->status);
    }
    else if(head != NULL){
        head = head->next;
        head->prev = NULL;
        curr->next = NULL;
        printf("Attention! %s is being served at %s table\n", curr->name, curr->status);
    }
    free(curr);
}

void printLine(){
    curr = head;
    int i = 1;
    if(head == NULL){
        printf("Queue is empty\n");
    }else{
        while(curr != NULL){
            printf("%d. %s\n", i, curr->name);
            curr = curr->next;
            i++; 
        }
    }
}

void dismissQueue(){
    curr = head;
    while(curr != NULL){
        head = head->next;
        free(curr);
        curr = head;
    }
    head = NULL;
    tail = NULL;
}

void serveAll(){
    curr = head;
    while(curr != NULL){
        head = head->next;
        printf("Attention! %s is being served at %s table\n", curr->name, curr->status);
        free(curr);
        curr = head;
    }
    head = NULL;
    tail = NULL;
}

void popAll(){
    curr = head;
    while(curr != NULL){
        head = head->next;
        free(curr);
        curr = head;
    }
    head = NULL;
    tail = NULL;
}

int main(){
    char name[50];
    char status[10];
    int pilihan = -1;

    do{
        puts("============================");
        puts("SUNIB Restaurant Reservation");
        puts("============================");
        puts("");
        puts("Waiting Line:");
        printLine();
        puts("");
        puts("1. Add Customer to Queue");
        puts("2. Serve One");
        puts("3. Serve All");
        puts("4. Dismiss Queue");
        puts("0. Exit");
        printf("Input Menu Number: ");
        scanf("%d", &pilihan);
        switch(pilihan){
            case 1:{
                scanf("%s ", status);
                scanf("%[^\n]", name);
                getchar();
                addCustomer(status, name);
                break;
            }
            case 2:{
                serveOne();
                break;
            }
            case 3:{
                serveAll();
                break;
            }
            case 4:{
                dismissQueue();
                printf("End of the day!\n");
                break;
            }
            case 0:{
                break;
            }
            default:{
                puts("Invalid Menu Number!\n");
                break;
            }
        }

    }while(pilihan != 0);
    popAll();
    return 0;
}

