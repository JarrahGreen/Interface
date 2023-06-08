#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main() {
    char Username[20];
    char Password[20];

    // Login
    printf("Username: ");
    fgets((char *) &Username, sizeof(Username), stdin);

    // Open file
    FILE *database = fopen("C:\\Users\\22000773\\CLionProjects\\Interface\\database.txt", "r");
    //Error check file
    if (database == NULL) {
        printf("Error! Could not open file\nError code: %d", errno);
        exit(-1);
    }

    //Read through file
    char checkUsername[100];
    char* result;
    do {
        result = fgets(checkUsername, sizeof checkUsername, database);
    } while(strcmp(Username, checkUsername) != 0 && result != NULL);
    if (strcmp(checkUsername, Username) == 0) {
        printf("in database");
    } else {
        printf("not in database");
    }



// Create a login
/*
    printf("Hello,\n Welcome to ____ please create a Username: \n");
    fgets((char *) &Username, sizeof(Username), stdin);


    FILE *database;
    database = fopen("C:\\Users\\22000773\\CLionProjects\\Interface\\database.txt", "a");

    // test for files not existing.
    if (database == NULL) {
        printf("Error! Could not open file\n");
        exit(-1);
    }
    // write to file vs write to screen
    fprintf(database, "%s\n", Username); // write to file
    fclose(database);
}






    database = fopen("database.txt");
    char output[100];
    fgets(output, 100, database);
    printf("%s", output);
    fclose(output);



*/
}