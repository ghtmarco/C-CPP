#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void logo(){
	
puts(" /$$$$$$$  /$$                                            /$$$$$$  /$$   /$$ /$$       /$$$$$$ /$$   /$$ /$$$$$$$$");
puts("| $$__  $$| $$                                           /$$__  $$| $$$ | $$| $$      |_  $$_/| $$$ | $$| $$_____/");
puts("| $$  \\ $$| $$       /$$   /$$ /$$$$$$$   /$$$$$$       | $$  \\ $$| $$$$| $$| $$        | $$  | $$$$| $$| $$      ");
puts("| $$$$$$$ | $$      | $$  | $$| $$__  $$ |____  $$      | $$  | $$| $$ $$ $$| $$        | $$  | $$ $$ $$| $$$$$   ");
puts("| $$__  $$| $$      | $$  | $$| $$  \\ $$  /$$$$$$$      | $$  | $$| $$  $$$$| $$        | $$  | $$  $$$$| $$__/   ");
puts("| $$  \\ $$| $$      | $$  | $$| $$  | $$ /$$__  $$      | $$  | $$| $$\\  $$$| $$        | $$  | $$\\  $$$| $$      ");
puts("| $$$$$$$/| $$$$$$$$|  $$$$$$/| $$  | $$|  $$$$$$$      |  $$$$$$/| $$ \\  $$| $$$$$$$$ /$$$$$$| $$ \\  $$| $$$$$$$$");
puts("|_______/ |________/ \\______/ |__/  |__/ \\_______/       \\______/ |__/  \\__/|________/|______/|__/  \\__/|________/");
                                                                                                                  
}

struct data {
    int level;
    char job[10];
    char name[21];
    int damage;
    struct data *left, *right, *parent;
} *root = NULL;

struct data *insert(struct data *curr, int insertDmg, int level, char name[21], char job[10], struct data *nodeParent) {
    srand(time(0));
    if (strcmp("Fighter", job) == 0) {
       insertDmg = level + (rand() % 50);
       }else if(strcmp("fighter", job)== 0){
       	insertDmg = level + (rand() % 50);
	   }else if (strcmp("rogue", job) == 0){
	   	insertDmg = level + (rand() % 25);
	   }else if (strcmp("Rogue", job) == 0) {
        insertDmg = level + (rand() % 25);
		}else if (strcmp("Mage", job) == 0){
    	insertDmg = level + (rand() % 75);
		}else if(strcmp("mage", job) == 0){
		insertDmg = level + (rand() %75);
	}
    if (curr == NULL) {
        curr = (struct data *)malloc(sizeof(struct data));
        curr->left = curr->right = NULL;
        curr->damage = insertDmg;
        curr->level = level;
        strcpy(curr->name, name);
        strcpy(curr->job, job);
        curr->parent = nodeParent;
    } else {
        if (insertDmg < curr->damage) {
            curr->left = insert(curr->left, insertDmg, level, name, job, curr);
        } else if (insertDmg > curr->damage) {
            curr->right = insert(curr->right, insertDmg, level, name, job, curr);
        }
    }
    return curr;
}

void printAll(struct data *curr){
    if (curr == NULL) {
        puts("\n\n--- There is No Character in The Tree ---\n");
    } else {
        if(curr->left != NULL) printAll(curr->left);
        if(curr != NULL){
            printf("--|---------------------|------------|------------|----------|----|\n");
            printf(" * %-20s : %-10s : lvl. %-5d :  damage  : %d\n", curr->name, curr->job, curr->level, curr->damage);
            printf("--|---------------------|------------|------------|----------|----|\n");
        }
        if(curr->right != NULL) printAll(curr->right);
    }
}

void inOrder(struct data *curr) {
    if (curr == NULL) {
        puts("--- There is No Character in The Tree ---\n");
    } else {
        if (curr->left != NULL) inOrder(curr->left);
        if (curr != NULL) {
            printf("In Order: %d \n", curr->damage);
        }
        if (curr->right != NULL) inOrder(curr->right);
    }
}

void postOrder(struct data *curr) {
    if (curr == NULL) {
        puts("--- There is No Character in The Tree ---\n");
    } else {
        if (curr->left != NULL) postOrder(curr->left);
        if (curr->right != NULL) postOrder(curr->right);
        if (curr != NULL) {
            printf("Post Order: %d \n", curr->damage);
        }
    }
}

void preOrder(struct data *curr) {
    if (curr == NULL) {
        puts("--- There is No Character in The Tree ---\n");
    } else {
        if (curr != NULL) {
            printf("Pre Order : %d \n", curr->damage);
        }
        if (curr->left != NULL) preOrder(curr->left);
        if (curr->right != NULL) preOrder(curr->right);
    }
}

struct data *popAll(struct data *curr) {
    if (curr == NULL) return NULL;
    curr->left = popAll(curr->left);
    curr->right = popAll(curr->right);
    free(curr);
    return NULL;
}

void animate() {
    printf("Loading characters");
    for(int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        Sleep(500);
    }
    printf("\n");
}

int main() {
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    int pilihan;
    char input[10];
    int insertDmg;
    char insertName[21];
    char job[10];
    int level;
    char enter = 0;

    do {
        system("cls");
        logo();
        printf("1. View All Character\n");
        printf("2. Add new Character\n");
        printf("3. In Order, Pre Order, Post Order Character's Damage\n");
        printf("4. Exit And Pop All\n\n");
        printf(">> Input Choice : ");
        scanf("%d", &pilihan);
        getchar();
        switch (pilihan) {
            case 1:{
                system("cls");
                animate();
                system("cls");
                printf("Character List: \n\n");
                printAll(root);
                printf("\n\n\nPress enter to continue...");
                while (getchar() != '\n');
                break;
            }
            case 2: {
                system("cls");
                
                do {
                    
                    printf("Input Character's Name [3 - 20][Non Space Char] : ");
                    scanf("%[^\n]", insertName); 
                    getchar();
                    
                    if(strlen(insertName) < 3 || strlen(insertName) > 20 || strchr(insertName, ' ') != NULL){
                        printf("Input Not Valid\n");
                    }
                    
                }while(strlen(insertName) < 3 || strlen(insertName) > 20 || strchr(insertName, ' ') != NULL);
                    
                do{
                    
                    printf("Input Character's Job [Fighter, Rogue, Mage] : ");
                    scanf("%s", job); getchar();
                    
                    if(strcmp("Fighter", job) != 0 && strcmp("fighter", job) != 0 && strcmp("Rogue", job) != 0 && strcmp("rogue", job) != 0 && strcmp("Mage", job) != 0 && strcmp("mage", job) != 0){
                        printf("Input Not Valid\n");
                    }
                    
                }while(strcmp("Fighter", job) != 0 && strcmp("fighter", job) != 0 && strcmp("Rogue", job) != 0 && strcmp("rogue", job) != 0 && strcmp("Mage", job) != 0 && strcmp("mage", job) != 0);

                do {
                    
                    printf("Input Character's Level [1-105] : ");
                    scanf("%d", &level);
                    getchar();
                    
                    if(level < 1 || level > 105){
                        printf("Input Not Valid\n");    
                       }
                       
                } while (level < 1 || level > 105);
                
                root = insert(root, insertDmg, level, insertName, job, NULL);
                printf("\n--- Add New Character Success ---");
                printf("\n\n\nPress enter to continue...");
                while (getchar() != '\n');
                break;
            }
            case 3:{
                system("cls");
                while(true){
                
                printf("\"In Order\", \"Post Order\", \"Pre Order\"\n");
                printf(">> ");  
                scanf("%[^\n]", input);
                getchar();
                
                if (strcmp("In Order", input) == 0){
                inOrder(root);
                break;  
                }else if (strcmp("Post Order", input) == 0){
                    postOrder(root);
                    break;
                }else if (strcmp("Pre Order", input) == 0){
                    preOrder(root);
                    break;
                }else{
                    printf("Input Not Valid\n");
                }
            }
                printf("\n\n\nPress Enter to continue...");
                while (getchar() != '\n');
                break;
            }
            case 4:{
				system("cls");
			    logo();
			    printf("Thank you for using Blue-Luna Online!\n");
			    printf("Have a great day ahead!\n");
			    printf("\nExiting");
			    for(int i = 0; i < 3; i++) {
			        printf(".");
			        fflush(stdout);
			        Sleep(500);
			    }
			    printf("\n");
                break;
            }
			default:{
				printf("Input Not Valid\n");
				printf(">> ");
				break;
			}
        }
            
    } while (pilihan != 4);
    
    root = popAll(root);
    return 0;
}