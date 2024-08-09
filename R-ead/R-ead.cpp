#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int i = 0;

struct Data {
    char location[50];
    char city[50];
    int price;
    int rooms;
    int bathrooms;
    int carPark;
    char type[50];
    char furnish[50];
} property[50000];

void menu() {
    printf("What do you want to do?\n");
    printf("1. Display Data\n");
    printf("2. Search Data\n");
    printf("3. Sort Data\n");
    printf("4. Export Data\n");
    printf("5. Exit\n");
    printf("Your choice: ");
}

void sortBy(char column[], char order[]) {
    int j;
    struct Data temp;

    if (strcmp(column, "Location") != 0 && strcmp(column, "City") != 0 &&
        strcmp(column, "Price") != 0 && strcmp(column, "Rooms") != 0 &&
        strcmp(column, "Bathrooms") != 0 && strcmp(column, "Carpark") != 0 &&
        strcmp(column, "Type") != 0 && strcmp(column, "Furnish") != 0) {
        printf("Invalid column!\n");
        return;
    }

    if (strcmp(order, "asc") != 0 && strcmp(order, "desc") != 0) {
        printf("Invalid order!\n");
        return;
    }

    for (int k = 0; k < i - 1; k++) {
        for (j = 0; j < i - k - 1; j++) {
            int cmp;
            if (strcmp(order, "asc") == 0) {
                if (strcmp(column, "Price") == 0 || strcmp(column, "Rooms") == 0 || strcmp(column, "Bathrooms") == 0 || strcmp(column, "Carpark") == 0) {
                    cmp = property[j].price - property[j + 1].price;
                } else if (strcmp(column, "Location") == 0 || strcmp(column, "City") == 0 || strcmp(column, "Type") == 0 || strcmp(column, "Furnish") == 0) {
                    cmp = strcmp(property[j].location, property[j + 1].location);
                } else if (strcmp(column, "Type") == 0 || strcmp(column, "Furnish") == 0) {
                    cmp = strcmp(property[j].type, property[j + 1].type);
                } else if (strcmp(column, "Furnish") == 0) {
                    cmp = strcmp(property[j].furnish, property[j + 1].furnish);
                } else {
                    cmp = 0;
                }
            } else {
                if (strcmp(column, "Price") == 0 || strcmp(column, "Rooms") == 0 || strcmp(column, "Bathrooms") == 0 || strcmp(column, "Carpark") == 0) {
                    cmp = property[j + 1].price - property[j].price;
                } else if (strcmp(column, "Location") == 0 || strcmp(column, "City") == 0 || strcmp(column, "Type") == 0 || strcmp(column, "Furnish") == 0) {
                    cmp = strcmp(property[j + 1].location, property[j].location);
                } else if (strcmp(column, "Type") == 0 || strcmp(column, "Furnish") == 0) {
                    cmp = strcmp(property[j + 1].type, property[j].type);
                } else if (strcmp(column, "Furnish") == 0) {
                    cmp = strcmp(property[j + 1].furnish, property[j].furnish);
                } else {
                    cmp = 0;
                }
            }

            if (cmp > 0) {
                temp = property[j];
                property[j] = property[j + 1];
                property[j + 1] = temp;
            }
        }
    }

    printf("Data found. Detail of data:\n");
    printf("%-25s %-20s %-10s %-10s %-10s %-10s %-15s %-10s\n",
           "Location", "City", "Price", "Rooms", "Bathrooms", "Carpark",
           "Type", "Furnish");

    for (int k = 0; k < (i < 10 ? i : 10); k++) {
        printf("%-25s %-20s %-10d %-10d %-10d %-10d %-15s %-10s\n",
               property[k].location, property[k].city, property[k].price, property[k].rooms,
               property[k].bathrooms, property[k].carPark, property[k].type, property[k].furnish);
    }
}


void selectRow(char header[]) {
    char search[100];

    printf("What data do you want to find? ");
    scanf("%s", search);
    int found = 0;
    for (int k = 0; k < i; k++) {
        if ((strcmp(header, "Location") == 0 && strcmp(search, property[k].location) == 0) || (strcmp(search, "City") == 0 && strcmp(search, property[k].city) == 0) ||
            (strcmp(header, "Price") == 0 && atoi(search) == property[k].price) || (strcmp(search, "Rooms") == 0 && atoi(search) == property[k].rooms) ||
            (strcmp(header, "Bathrooms") == 0 && atoi(search) == property[k].bathrooms) || (strcmp(search, "Carparks") == 0 && atoi(search) == property[k].carPark) ||
            (strcmp(header, "Type") == 0 && strcmp(search, property[k].type) == 0) || (strcmp(search, "Furnish") == 0 && strcmp(search, property[k].furnish) == 0)) {
            if (!found) {
                printf("%-25s %-20s %-10s %-10s %-10s %-10s %-15s %-10s\n",
                       "Location", "City", "Price", "Rooms", "Bathrooms", "Carparks",
                       "Type", "Furnish");
            }
            printf("%-25s %-20s %-10d %-10d %-10d %-10d %-15s %-10s\n",
                   property[k].location, property[k].city, property[k].price, property[k].rooms,
                   property[k].bathrooms, property[k].carPark, property[k].type, property[k].furnish);

            found = 1;
        }
    }

    if (!found) {
        printf("Data not found!\n");
    }
}

void writeFile(char name[]){
    FILE *file = fopen(name, "w");
    fprintf(file, "%-25s %-12s %-10s %-6s %-10s %-9s %-10s %-10s\n",
           "Location", "City", "Price", "Rooms", "Bathrooms", "Carparks",
            "Type", "Furnish");

    for(int j = 0; j < i; j++){
        fprintf(file, "%-25s %-12s %-10d %-6d %-10d %-9d %-10s %-12s\n",
               property[j].location, property[j].city, property[j].price, property[j].rooms,
                property[j].bathrooms, property[j].carPark, property[j].type, property[j].furnish);
    }
    fclose(file);
    printf("Data successfully written to file %s.csv!\n", name);
}

void readFile() {
    i = 0;
    FILE *fp;
    fp = fopen("file.csv", "r");
    char title[1005];
    fscanf(fp, "%[^\n]\n", title);
    while (!feof(fp)) {
        fscanf(fp, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%s\n", property[i].location, property[i].city, &property[i].price,
               &property[i].rooms, &property[i].bathrooms, &property[i].carPark, property[i].type, property[i].furnish);
        i++;
    }

    fclose(fp);
}

int main() {
    int pilihan;
    int rows;
    char search[100];
    char name[100];
    char column[100];
    char order[100];
    readFile();
    do {
        menu();
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                printf("Number of rows: ");
                if (scanf("%d", &rows) != 1 || rows <= 0) {
                    puts("");
                    printf("Input must be a positive integer\n");
                    puts("");
                    break;
                }
                puts("");
                printf("%-25s %-20s %-10s %-10s %-10s %-10s %-15s %-10s\n", "Location", "City", "Price", "Rooms",
                       "Bathrooms", "CarParks", "Type", "Furnish");
                for (i = 0; i < rows; i++) {
                    printf("%-25s %-20s %-10d %-10d %-10d %-10d %-15s %-10s\n", property[i].location,
                           property[i].city, property[i].price, property[i].rooms, property[i].bathrooms,
                           property[i].carPark, property[i].type, property[i].furnish);
                }
                puts("");
                break;
            case 2:
                printf("Choose column: ");
                scanf("%s", search);
                getchar();
                selectRow(search);
                break;
            case 3:
                printf("Choose column: ");
                scanf("%s", column);
                printf("Sort Ascending or escending? ");
                scanf("%s", order);
                sortBy(column, order);
                break;
            case 4:
                printf("File Name: ");
                scanf("%s", name);
                writeFile(name);
                break;
            case 5:
                puts("THANK YOU FOR USING THE PROGRAM");
                break;
            default:
                puts("");
                puts("INVALID COMMAND");
                puts("");
                break;
        }
    } while (pilihan != 5);

    return 0;
}
