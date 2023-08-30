
#define MAX_SIZE 1000
#include <string.h>
#include <stdio.h>
char* storage();
int main() {
    int count=0;
    char line[1000];
    struct poem_{
        char lines[10000];
        char title[100];
        char description[100];
        char date[100];
        char category[100];
        char author[100];
    };

    char* lines=storage();
    char title[100];
    char description[100];
    char date[100];
    char category[100];
    char author[100];
    printf("Enter title of the poem: ");
    gets(title);
    printf("Enter description of the poem: ");
    gets(description);
    printf("Enter date of the post: ");
    gets(date);
    printf("Enter category of the poem: ");
    gets(category);
    printf("Enter author of the poem: ");
    gets(author);

    struct poem_ poem_instance;
    strcpy(poem_instance.title, title);
    strcpy(poem_instance.lines, lines);
    strcpy(poem_instance.description, description);
    strcpy(poem_instance.date, date);
    strcpy(poem_instance.category, category);
    strcpy(poem_instance.author, author);
    FILE *poem_db;
    char filename[1000];
    char filepath[1000]; 
    snprintf(filepath, sizeof(filepath), "logs/%s.txt", poem_instance.title);
    poem_db=fopen(filepath,"w");
    
    snprintf(filename, sizeof(filename),"/mnt/e/first_year_c_project/sahitya_sathi/content/posts/%s.md", poem_instance.title);
    poem_db=fopen(filepath,"w");

    fprintf(poem_db,"%s--%s--%s--%s--%s--%s\n",poem_instance.lines,poem_instance.title,poem_instance.description,poem_instance.date,poem_instance.category,poem_instance.author);
    fclose(poem_db);
   
   
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
    
    fprintf(file, "---\n"
                  "title: \"%s\"\n"
                  "description: \"%s\"\n"
                  "date: %s\n"
                  "categories: [\"%s\"]\n"
                  "authors: [\"%s\"]\n"
                  "tags: [\"%s\"]\n"
                  "---\n"
                  "\n"
                  "\n"
                  
                  "```\n"
                  "%s\n"
                  "```",title,description,date,category,author,title,lines);
                  
    fclose(file);
    
    FILE *poem_db__;

    poem_db__=fopen("poem_db.txt","r");
   
       
    
    fclose(poem_db__);
//    FILE* poem_db11 = fopen("poem_db.txt", "r");
//     if (poem_db11 == NULL) {
//         perror("Error opening poem_db.txt");
//         return 1;
//     }
//       FILE* poem_db__1 = fopen("poem_db.txt", "r");
//     if
   


    

//     while (fscanf(poem_db11, "%s--%s--%s--%s--%s--%s\n", 
//                   poem_instance.lines, poem_instance.title, poem_instance.description,
//                   poem_instance.date, poem_instance.category, poem_instance.author) == 6) {
//         printf("Lines: %s\n", poem_instance.lines);
//         printf("Title: %s\n", poem_instance.title);
//         printf("Description: %s\n", poem_instance.description);
//         printf("Date: %s\n", poem_instance.date);
//         printf("Category: %s\n", poem_instance.category);
//         printf("Author: %s\n", poem_instance.author);
        
//     }

//     fclose(poem_db11);
//     return 0;
}


#include <string.h>
#include <stdlib.h>
 char* storage() {
    
    char input[MAX_SIZE];
    char* lines = malloc(MAX_SIZE); // Allocate memory for the string
    lines[0] = '\0';

    printf("Enter multiple lines of text (enter 'end' to finish):\n");

    while (1) {
        fgets(input, MAX_SIZE, stdin);

        // Check if the user wants to finish entering lines
        if (strcmp(input, "end\n") == 0) {
            break;
        }

        // Append the input line to the existing lines
        strcat(lines, input);
    }

    

    return lines;
}