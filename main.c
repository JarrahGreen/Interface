#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
int main() {
    // Open file
    FILE *database = fopen("..\\database.txt", "r");
    //Error check file
    if (database == NULL) {
        printf("Error! Could not open file\nError code: %d", errno);
        exit(-1);
    }
}
*/



int login(char* username) {
    // Open file
    FILE *database = fopen("..\\database.txt", "r");
    //Error check file
    if (database == NULL) {
        printf("Error! Could not open file\nError code: %d", errno);
        exit(-1);
    }

    //Read through file
    char checkUsername[100];
    char *result;
    do {
        result = fgets(checkUsername, sizeof checkUsername, database);
    } while (strcmp(username, checkUsername) != 0 && result != NULL);
    fclose(database);
    if (strcmp(checkUsername, username) == 0) {
        printf("Login Success");
        return 0;
    }
    printf("Login Failure");
    return 1;
}

int createUser(char* username) {
    printf("Hello,\n Welcome to ____ please create a Username: \n");
    fgets(username, sizeof(username), stdin);


    FILE* database = fopen("..\\database.txt", "a");

    // test for files not existing.
    if (database == NULL) {
        printf("Error! Could not open file\n");
        exit(-1);
    }
    // write to file vs write to screen
    fprintf(database, "%s\n", username); // write to file
    fclose(database);
}

int main() {

    char Username[20];
    char Password[20];



    // Login
    printf("Menu\n"
                "1: Login\n"
                "2: Create user\n"
                "> ");
    char input[2];
    fgets(input, sizeof(input), stdin);

    fgets(Username, sizeof(Username), stdin);
    if (login(Username) == 0) {
        printf("User does not exist, would you like to create it?: (y/N)");
    }

// Create a login

}