#include <stdio.h>
#include <stdlib.h>

struct data{
	int value;
	struct data *next;
}*head, *tail, *curr;

void pushHead(int insertedValue){
	curr = (struct data *)malloc(sizeof(struct data));
	curr->value = insertedValue;
	curr->next = NULL;
	if(head == NULL){
		head = tail = curr;
	}
	else{
		curr->next = head;
		head = curr;
	}
}

void pushTail(int insertedValue){
	curr = (struct data *)malloc(sizeof(struct data));
	curr->value = insertedValue;
	curr->next = NULL;
	if(head == NULL){
		head = tail = curr;
	}
	else{
		tail->next = curr;
		tail = curr;
	}
}

void pushMid(int insertedValue){
	curr = (struct data *)malloc(sizeof(struct data));
	curr->value = insertedValue;
	curr->next = NULL;
	if(head == NULL){
		head = tail = curr;
	}
	else if(curr->value > tail->value){
		pushTail(insertedValue);
	}
	else if(curr->value < head->value){
		pushHead(insertedValue);
	}
	else{
		struct data *temp;
		temp = head;
		while(temp->next->value < curr->value){
			temp = temp->next;
		}
		curr->next = temp->next;
		temp->next = curr;
	}
}

void popHead(){
	if(head != NULL){
		curr = head;
		head = head->next;
		free(curr);
	}
	if(head == NULL){
		head = tail = NULL;
	}
}

void popTail(){
	if(head == tail){
		head = tail = NULL;
	}
	if(head != NULL){
		struct data *temp;
		temp = head;
		while(temp->next != tail){
			temp = temp->next;
		}
		curr = tail;
		tail = temp;
		free(curr);
		tail->next = NULL;
	}
}

void popMid(int insertedValue){
	if(head == NULL){
		head == tail == NULL;
	}
	if(head->value == insertedValue){
		popHead();
	}
	else if(tail->value == insertedValue){
		popTail();
	}
	else{
		struct data *temp;
		temp = head;
		while(temp->next->value != insertedValue && temp != tail){
			temp = temp->next;
		}
		curr = temp->next;
		temp->next = temp->next->next;
		free(curr);
	}
}

void print(){
	if(head == NULL){
		printf("No Data\n");
	}
	else{
		curr = head;
		while(curr != NULL){
			printf("%d -> ", curr->value);
			curr = curr->next;
		}
		printf("\n");
	}
}

void popAll(){
	curr = head;
	while(curr != NULL){
		head = head->next;
		free(curr);
		curr = head;
	}
}

int main(){
	
	int pilihan;
	int value;
	
	do{
		print();
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Exit\n");
		printf("Masukkan Pilihan : ");
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1:{
				printf("Masukkan Value : ");
				scanf("%d", &value);
				pushMid(value);
				break;
			}
			case 2:{
				printf("Masukkan Value : ");
				scanf("%d", &value);
				popMid(value);
				break;
			}
		}
	}while(pilihan != 3);
	popAll();
	
	return 0;
}
