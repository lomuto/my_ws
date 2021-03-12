#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLKSIZE 10

struct node{
    struct node *prev;
    struct node *next;
    int val;
};

typedef struct node NODE;

void SEEK(NODE* node){
        for(NODE* ptr = node->next;;ptr=ptr->next){
            if(ptr->next == NULL)
                break;
            printf("%d ",ptr->val);
        }
    printf("\n");
    printf("SEEK Completed\n\n");
}

void ADD(NODE* head,int node_num,int num){
    int cnt=0;
    for(NODE* ptr = head;(ptr->next!=NULL)||(cnt == node_num);ptr=ptr->next){
        if(node_num == cnt){
            NODE* new_node = malloc(sizeof(NODE));
            NODE* ptr2 = ptr->prev;

            new_node->val = num;
                
            ptr->prev = new_node;
            new_node->next = ptr;

            ptr2->next = new_node;
            new_node->prev = ptr2;
            printf("ADD completed\n\n");
            return;
        }
        cnt++;
    }
    printf("Failed to ADD\n\n");
}

void REMOVE(NODE* head, int node_num){
    int cnt = 0;
    for(NODE* ptr = head;ptr->next!=NULL;ptr=ptr->next){
        if(node_num == cnt){
            NODE* ptr2 = ptr->prev;
            ptr = ptr->next;

            free(ptr->prev);

            ptr->prev = ptr2;
            ptr2->next = ptr;

            printf("Remove Completed\n");
            return;
        }
        cnt++;
    }
    printf("Failed to Remove\n");
}

void SEARCH(NODE* head, int node_val){
    int cnt = 0;
    for(NODE* ptr = head;ptr->next!=NULL;ptr=ptr->next){
        if(ptr->val == node_val){
            printf("value %d in node number [%d]\n",node_val,cnt);
            return;
        }
        cnt++;
    }
    printf("Failed to Search\n");
}

void QUIT(NODE* head){
    NODE* ptr = head;
    if((head->next->next) == NULL)
        exit(EXIT_SUCCESS);
    else{
        for(ptr = ptr->next;;ptr=ptr->next){
            free(ptr->prev);
            if((ptr->next) == NULL){
                free(ptr);
                exit(EXIT_SUCCESS);
            } 
        }
    }
}

int main(){
    NODE* head = malloc(sizeof(NODE));
    NODE* tail = malloc(sizeof(NODE));

    head->next = tail;
    tail->next=NULL;
    
    tail->prev = head;
    head->prev = NULL;

    char BUFFER[BLKSIZE+1];

    int temp1,temp2;

    printf("[Enter \"q\" for exit]\n");
    printf("$");

    for(fgets(BUFFER,BLKSIZE+1,stdin); ;fgets(BUFFER,BLKSIZE+1,stdin)){
        BUFFER[strlen(BUFFER)-1] = '\0';

        if(!strcmp(BUFFER,"ADD")){
            printf("Enter a number of node and value to add: ");
            scanf("%d %d",&temp1,&temp2);
            while(getchar()!='\n');         //buffer clearing
            ADD(head,temp1,temp2);
        }
        else if(!strcmp(BUFFER,"REMOVE")){
            printf("Enter a number of node to remove: ");
            scanf("%d",&temp1);
            while(getchar()!='\n');         //buffer clearing
            REMOVE(head,temp1);
        }
        else if(!strcmp(BUFFER,"SEARCH")){
            printf("Enter a value of node to search: ");
            scanf("%d",&temp1);
            while(getchar()!='\n');
            SEARCH(head,temp1);
        }
        else if(!strcmp(BUFFER,"SEEK")){
            SEEK(head);
        }
        else if(!strcmp(BUFFER,"q")){
            QUIT(head);
        }
        else
        {
            printf("Unavailable command. Try again\n");
        }

        printf("$");
    }

}

