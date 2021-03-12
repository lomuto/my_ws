/* REVERSE STRING */

// HELLO EVERY ONE MY NAME IS
// ==> is name my one every hello

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define WORDLEN 20
#define STRLEN 100

struct node{
	struct node* next;
	struct node* prev;
	char word[WORDLEN+1];
};

typedef struct node NODE;

int ADD(NODE* tail,char* word){
	if(word == NULL)
		return 0;
	NODE* new_node = malloc(sizeof(NODE));
	strcpy(new_node->word,word);

	NODE* ptr = tail;               // tricky to handel the right sequence to add node while sustain list's connectivitiy
	ptr->prev->next = new_node;     // 1. make prev node to point new node
	new_node->prev = ptr->prev;     // 2. make new node's prev pointer to reference prev node
	ptr->prev = new_node;           // 3.4. same for next node for as prev node
	new_node->next = ptr;
	
	return 1;
}

void LOWER(char* str){
	for(int i=0; *(str+i) != NULL; i++)
		if(isalpha(*(str+i))){
			*(str+i) = tolower(*(str+i));
		}
}

void R_print(NODE* tail){
	for(NODE* ptr = tail->prev;;ptr = ptr->prev){
		printf("%s",ptr->word);
		if(ptr->prev->prev == NULL){
			printf("\n");
			return;
		}
		else
		{
			printf(" ");
		}
		
	}
}

int main() {
	NODE* head = malloc(sizeof(NODE));
	NODE* tail = malloc(sizeof(NODE));

	head->prev = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->prev = head;

	char temp[STRLEN+1];
	printf("Enter string to revers:");
	fgets(temp,STRLEN+1,stdin);
	*(temp+strlen(temp)-1) = '\0';

	LOWER(temp);
    // this for loop is ART ^^
	for(ADD(tail,strtok(temp," "));ADD(tail,strtok(NULL," "));)     // ADD will return 0 to terminate loop when strtok is NULL
		;

	R_print(tail);
}