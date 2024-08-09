#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1007

int count = 0;

struct data {
    char name[51];
    char author[51];
    char isbn[14];
    char id[14];
    int pageNumber;

    struct data *next;
} *table[SIZE], *curr;

void generateId(char name[51], char author[51], char isbn[14], char id[14]) {
    count++;

    if ((author[0] >= 'a') && (author[0] <= 'z')) {
        author[0] -= 'a' - 'A';
    }
    char a = author[0];
    if ((name[0] >= 'a') && (name[0] <= 'z')) {
        name[0] -= 'a' - 'A';
    }
    char t = name[0];

    sprintf(id, "B%05d-%s-%c%c", count, isbn, a, t);
}

struct data *newBook(char name[51], char author[51], char isbn[14], int pageNumber) {
    struct data *curr = (struct data *)malloc(sizeof(struct data));

    char id[14];
    generateId(name, author, isbn, id);

    strcpy(curr->isbn, isbn);
    strcpy(curr->name, name);
    strcpy(curr->author, author);
    strcpy(curr->id, id);
    curr->pageNumber = pageNumber;
    curr->next = NULL;

    return curr;
}

int hash(char id[14]) {
    int key;
    int len = strlen(id);
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += id[i];
    }

    key = sum % SIZE;
    return key;
}

struct data *insert(char name[51], char author[51], char isbn[14], int pageNumber) {
    curr = newBook(name, author, isbn, pageNumber);
    int key = hash(curr->id);

    if (table[key] == NULL) {
        table[key] = curr;
    } else {
        struct data *temp = table[key];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = curr;
    }
    return curr;
}

void print() {
    if (count == 0) {
        printf("There are no books!\n");
    } else {
        printf("+--------------+----------------------+-------------+\n");
        printf("|  Book ID     |      Book Title      | Book author |\n");
        printf("+--------------+----------------------+-------------+\n");

        for (int i = 0; i < SIZE; i++) {
            struct data *curr = table[i];

            while (curr != NULL) {
                printf("| %-13s| %-21s| %s |\n", curr->id, curr->name, curr->author);
                curr = curr->next;
            }
        }

        printf("+--------------+----------------------+------------+\n");
    }
}

int main() {
    int pilihan;
    char name[100];
    char author[100];
    char isbn[14];
    int pageNumber;

    srand(time(NULL));

    do {
        system("cls");
        puts("Algodemy Library");
        puts("=================");
        puts("1. View Book");
        puts("2. Insert Book");
        puts("3. Remove Book");
        puts("4. Exit");
        printf(">> ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1: {
                system("cls");
                print();
                printf("\nPress Enter to continue...");
                getchar();
                break;
            }
            case 2: {
                printf("Enter the name of the book: ");
                scanf(" %[^\n]", name);
                getchar();
                printf("Enter the author of the book: ");
                scanf(" %[^\n]", author);
                getchar();
                printf("Enter the ISBN of the book: ");
                scanf(" %[^\n]", isbn);
                getchar();
                printf("Enter the page number of the book: ");
                scanf("%d", &pageNumber);
                insert(name, author, isbn, pageNumber);
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                system("cls");
                puts("Thank you for using this Program!");
                puts("");
                puts("Have a nice day~");
                break;
            }
        }
    } while (pilihan != 4);

    return 0;
}
