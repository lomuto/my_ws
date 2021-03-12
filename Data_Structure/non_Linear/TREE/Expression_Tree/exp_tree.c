#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"

struct node{
	char op;
	struct node *left_child,*right_child;	// int* a,b ==> int* a, int b. not int* b
};

typedef struct node NODE;

NODE* root_ptr;

NODE* init_node(){
	NODE* node = malloc(sizeof(NODE));
	node->left_child = NULL;
	node->right_child = NULL;

	return node;
}

void make_EXPtree(const char* EXP){

	for(;*EXP;EXP++){
		NODE* new_node = init_node();
		if(isdigit(*EXP)){
			new_node->op = *EXP;
			push((void*)new_node);
		}
		else{
			NODE* operator = new_node;
			operator->op = *EXP;
			
			operator->right_child = (NODE*)pop();
			operator->left_child = (NODE*)pop();
			
			root_ptr = operator;

			push((void*)operator);
		}
	}
}

void POSTORDER(NODE* node){
	if(node){
		POSTORDER(node->left_child);
		POSTORDER(node->right_child);
		printf("%c ",node->op);
	}
}

int evaluate_tree(NODE* node){
	if(!node->left_child || !node->right_child)
		return node->op;
	
	int op1 = evaluate_tree(node->left_child);	// 트리 만들 떄 왼쪽에서 오른쪽 순서로 연산하도록 수식트리 생성
	int op2 = evaluate_tree(node->right_child);

	switch(node->op)
	{
		case '+': return (op1-'0') + (op2-'0') + '0';
		case '-': return (op1-'0') - (op2-'0') + '0';
		case '*': return (op1-'0') * (op2-'0') + '0';
		case '/': return (op1-'0') / (op2-'0') + '0';
	}
}

int main() {
	char EXP[MAX_EXP];
	printf("Enter expression: ");
	scanf("%s", EXP);

	parentheses_check(EXP);

	int EXP_LEN = strlen(EXP);
	to_POSTFIX(EXP, EXP_LEN);

	//printf("POSTFIX expression is [ %s ]\n", EXP);
	clear_STACK();

	make_EXPtree(EXP);

	printf("POSTORDER for Expression Tree: ");
	POSTORDER(root_ptr);
	printf("\n");

	printf("evaluate: %d\n",evaluate_tree(root_ptr)-'0');
}