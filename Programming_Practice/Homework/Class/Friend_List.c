#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *catalog;
    char file[1024], name[1024], phone[1024], birthday[1024];
    printf("Input file name: ");
    scanf("%s", file);  // input file name
    if ((catalog = fopen(file, "r+")) == NULL) {
        printf("Error: Cannot open\n");  // error message if file does not exist or can't be opened
        return 0;
    } else {
        printf("%s successfully opened\n", file);  // success message
    }
    while (1) {
        char mode_choose[1024] = {0};
        // rewind(catalog);
        printf("Mode 1 for output friend list\n");
        printf("Mode 2 for add new friend to list\n");
        printf("Mode: ");
        scanf("%s", mode_choose);  // input mode
        int temp = 0;
        int mode = atoi(mode_choose);
        if (mode == 1) {
            printf("================================================================\n");
            while (fscanf(catalog, "%s%s%s", name, phone, birthday) != EOF) {  // print the whole catalog
                printf("%s's phone number: %s\n", name, phone);
                printf("%s's birthday: %s\n", name, birthday);
                printf("================================================================\n");
            }
        } else if (mode == 2) {
            rewind(catalog);

            temp = ftell(catalog);
            printf("%d\n", temp);

            fseek(catalog, 0, SEEK_END);

            temp = ftell(catalog);
            printf("%d\n", temp);

            printf("Name: ");
            scanf("%s", name);
            printf("Phone number: ");
            scanf("%s", phone);
            printf("Birthday: ");
            scanf("%s", birthday);
            fprintf(catalog, "%s %s %s\n", name, phone, birthday);  // add info to the catalog
            // fwrite(name, sizeof(char), strlen(name), catalog);
            // fwrite(" ", sizeof(char), 1, catalog);
            // fwrite(phone, sizeof(char), strlen(phone), catalog);
            // fwrite(" ", sizeof(char), 1, catalog);
            // fwrite(birthday, sizeof(char), strlen(birthday), catalog);
            // fwrite("\n", sizeof(char), 1, catalog);
            setbuf(stdin, NULL);
        } else {
            printf("Invalid\n");
        }
    }
    fclose(catalog);
}