#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    char NIM[15];
    char name[50];
    char degree[100];

    struct data* next;
    struct data* prev;
}*head = NULL, * tail = NULL, * curr;

void printCentered(char* text) {
    int totalWidth = 80;
    int length = strlen(text);
    int padding = (totalWidth - length) / 2;
    printf("%*s%s\n", padding, "", text);
}

void logo(){    
                                                                                                                                                            
puts(" ____   ____  _____   ______    ____  ____      ____      ______        _____            ______   _________________  _____      _____  ____             ______   ");
puts("|    | |    ||\\    \\ |\\     \\  |    ||    |    |    | ___|\\     \\   ___|\\    \\       ___|\\     \\ /                 \\|\\    \\    /    /||    |        ___|\\     \\  ");
puts("|    | |    | \\\\    \\| \\     \\ |    ||    |    |    ||     \\     \\ |    |\\    \\     |    |\\     \\\\______     ______/| \\    \\  /    / ||    |       |     \\     \\ ");
puts("|    | |    |  \\|    \\  \\     ||    ||    |    |    ||     ,_____/||    | |    |    |    |/____/|   \\( /    /  )/   |  \\____\\/    /  /|    |       |     ,_____/|");
puts("|    | |    |   |     \\  |    ||    ||    |    |    ||     \\--'\\_|/|    |/____/  ___|    \\|   | |    ' |   |   '     \ |    /    /  / |    |  ____ |     \\--'\\_|/");
puts("|    | |    |   |      \\ |    ||    ||    |    |    ||     /___/|  |    |\\    \\ |    \\    \\___|/       |   |          \\|___/    /  /  |    | |    ||     /___/|  ");
puts("|    | |    |   |    |\\ \\|    ||    ||\\    \\  /    /||     \\____|\\ |    | |    ||    |\\     \\         /   //              /    /  /   |    | |    ||     \____|\ ");
puts("|\\___\\_|____|   |____||\\_____/||____|| \\ ___\\/___ / ||____ '     /||____| |____||\\ ___\\|_____|       /___//              /____/  /    |____|/____/||____ '     /|");
puts("| |    |    |   |    |/ \\|   |||    | \\ |   ||   | / |    /_____/ ||    | |    || |    |     |      |`   |              |`    | /     |    |     |||    /_____/ |");
puts(" \\|____|____|   |____|   |___|/|____|  \\|___||___|/  |____|     | /|____| |____| \\|____|_____|      |____|              |_____|/      |____|_____|/|____|     | /");
puts("    \\(   )/       \\(       )/    \\(      \\(    )/      \\( |_____|/   \\(     )/      \\(    )/          \\(                   )/           \\(    )/     \\( |_____|/ ");
puts("     '   '         '       '      '       '    '        '    )/       '     '        '    '            '                   '             '    '       '    )/    ");
puts("                                                             '                                                                                             '     ");

}

struct data* insert(char NIM[], char name[], char degree[]) {
    curr = (struct data*)malloc(sizeof(struct data));
    curr->next = curr->prev = NULL;
    strcpy(curr->NIM, NIM);
    strcpy(curr->name, name);
    strcpy(curr->degree, degree);

    if (head == NULL) {
        head = tail = curr;
    }
    else {
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
    }
    return curr;
}

void Delete(char deleteData[]) {
    if (head == NULL) {
        printf("No Student Data...\n");
        return;
    }
    else {
        curr = head;
        while (curr != NULL) {
            if (strcmp(curr->name, deleteData) == 0) {
                if (curr == head) {
                    head = curr->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                    free(curr);
                    printf("Student '%s' Deleted.\n", deleteData);
                    return;
                }
                else if (curr == tail) {
                    tail = curr->prev;
                    tail->next = NULL;
                    free(curr);
                    printf("Student '%s' Deleted.\n", deleteData);
                    return;
                }
                else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    free(curr);
                    printf("Student '%s' Deleted.\n", deleteData);
                    return;
                }
            }
            curr = curr->next;
        }
        printf("Student With Name '%s' Not Found.\n", deleteData);
    }
}

void search(char searchData[]) {
    if (head == NULL) {
        printf("No Student Data...\n");
        return;
    }
    else {
        curr = head;
        while (curr != NULL) {
            if (strcmp(curr->NIM, searchData) == 0) {
                printf("Student With NIM '%s' Found.\n", searchData);
                printf("Student's Name: %s\n", curr->name);
                printf("Student's Major: %s\n", curr->degree);
                return;
            }
            curr = curr->next;
        }
    }
    printf("Data With NIM '%s' Not Found.\n", searchData);
}

void printAll() {
    curr = head;
    if (head == NULL) {
        printf("No Student Data...\n");
    }
    else {
        printf("| %-15s | %-20s | %-50s |\n", "NIM", "Name", "Major");
        while (curr != NULL) {
            printf("| %-15s | %-20s | %-50s |\n", curr->NIM, curr->name, curr->degree);
            curr = curr->next;
        }
    }
}

void popAll() {
    if (head != NULL) {
        curr = head;
        while (curr != NULL) {
            head = head->next;
            free(curr);
            curr = head;
        }
    }
}

int main() {
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    
    printCentered("");
    logo();
    printCentered("");
    printf("Press Enter to Continue...");
    getchar();

    int choice = -1;
    char NIM[15], name[50], degree[100];
    char deleteData[50], searchNIM[15];

    do {
        system("cls");
        puts("Linked List University");
        puts("======================");
        puts("1. View Student Data");
        puts("2. Add New Student");
        puts("3. Delete Student");
        puts("4. Search Student");
        puts("0. Exit");
        puts("");
        printf(">> ");

        scanf("%d", &choice); getchar();
        switch (choice) {
        case 1: {
            system("cls");
            printAll();
            puts("");
            printf("Press Enter to Continue...");
            getchar();
            break;
        }
        case 2: {
            system("cls");
            printf("Enter Student's NIM: ");
            scanf("%s", NIM); getchar();
            printf("Enter Student's Name: ");
            scanf("%[^\n]", name); getchar();
            printf("Enter Student's Major: ");
            scanf("%[^\n]", degree); getchar();
            insert(NIM, name, degree);
            printf("Student added successfully.\n");
            printf("Press Enter to Continue...");
            getchar();
            break;
        }
        case 3: {
            system("cls");
            printAll();
            printf("Enter name of student to delete: ");
            scanf("%[^\n]", deleteData); getchar();
            Delete(deleteData);
            printf("Press Enter to Continue...");
            getchar();
            break;
        }
        case 4: {
            system("cls");
            printf("Enter NIM of student to search: ");
            scanf("%s", searchNIM); getchar();
            search(searchNIM);
            printf("Press Enter to Continue...");
            getchar();
            break;
        }
        case 0: {
            break;
        }
        default: {
            puts("Invalid Input!");
            printf("Press Enter to Continue...");
            getchar();
            break;
        }
        }
    } while (choice != 0);
    popAll();
    return 0;
}
