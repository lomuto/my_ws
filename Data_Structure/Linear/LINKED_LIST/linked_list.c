#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20

struct node{
    struct node *next;
    char day[MAX_LEN+1];
};

typedef struct node NODE;

int main(){

    NODE* head = malloc(sizeof(NODE));
    NODE* mon = malloc(sizeof(NODE));
    NODE* tue = malloc(sizeof(NODE));
    NODE* thu = malloc(sizeof(NODE));

    head->next = mon;

    strcpy(mon->day,"Monday");
    mon->next = tue;
    strcpy(tue->day,"Tuesday");
    tue->next = thu;
    strcpy(thu->day,"Thursday");
    thu->next = NULL;

    printf("\n");
    printf("Current List is:");
    for(NODE* ptr = head->next; ;ptr = ptr->next){
        printf("%s ",ptr->day);
        if(ptr->next == NULL)
            break;
    }
    printf("\n");
    printf("\n");

    // ADD

    NODE* wed = malloc(sizeof(NODE));
    tue->next = wed;
    strcpy(wed->day,"Wednesday");
    wed->next = thu;

    printf("Add Wednesday\n");
    for(NODE* ptr = head->next; ;ptr = ptr->next){
        printf("%s ",ptr->day);
        if(ptr->next == NULL)
            break;
    }

    printf("\n");
    printf("\n");

    // REMOVE

    free(thu);
    wed->next = NULL;

    printf("Remove Thursday\n");
    for(NODE* ptr = head->next; ;ptr = ptr->next){
        printf("%s ",ptr->day);
        if(ptr->next == NULL)
            break;
    }

    printf("\n");
    printf("\n");

    // ADD

    NODE* sun = malloc(sizeof(NODE));
    head->next = sun;
    strcpy(sun->day,"Sunday");
    sun->next=mon;


    printf("Add Sunday\n");
    for(NODE* ptr = head->next; ;ptr = ptr->next){
        printf("%s ",ptr->day);
        if(ptr->next == NULL)
            break;
    }

    printf("\n");
    printf("\n");

    // SEARCH

    printf("Search Tuesday\n");
    int count=0;
    for(NODE* ptr = head->next; ;ptr = ptr->next){
        count++;
        if(!strcmp(ptr->day,"Tuesday")){
            printf("list [%d] is Tuesday\n",count);
        }
    }
    printf("\n");

    return 0;
}