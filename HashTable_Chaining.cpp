#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{

    char key[51];
    struct data *next;
    struct data *prev;

    char nim[11];
    int tinggi;
    float berat;


}*head[26], *tail[26], *curr;

int hashFirstChar(char insertVall[51]){
    int hashKey = insertVall[0] - 97;

    curr = (struct data*) malloc(sizeof(struct data));
    curr->next = NULL;
    strcpy(curr->key, insertVall);


    if(head[hashKey] == NULL){
        head[hashKey] = tail[hashKey] = curr;
    }else{
        tail[hashKey]->next = curr;
        tail[hashKey] = curr;
    }
    tail[hashKey]->next = NULL;
}

void popAll(){
    int i;
    for(i = 0; i < 26; i++){
        curr = head[i];
        while(curr != NULL){
            head[i] = head[i]->next;
            free(curr);
            curr = head[i];
        }
    }
}

void print(struct data h[26]){
    int i;
    printf("Index | Key\n");
    for(int i; i < 26; i++){
        curr = head[i];
        printf("%5d | ", i);
        while(curr != NULL){
            printf("%-10s -> ", curr->key);
            curr = curr->next;

        }
        printf("\n");
    }
}

int main(){
    char insertVal[51];
    struct data h[26] = {};
do{
    print(h);
    printf("Masukan Key : ");
    scanf("%s", insertVal);
    getchar();

    hashFirstChar(insertVal);
    

    
}while(strcmp(insertVal, "Exit") != 0);
    popAll();
    return 0;
}