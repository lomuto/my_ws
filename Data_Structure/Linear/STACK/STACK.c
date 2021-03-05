#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define STACK_SIZE 10000

int STACK[STACK_SIZE] = { 0, };
int* ptr = STACK - 1;

void push(int);
int pop();
int size();
bool empty();
int top();


int main() { 
	int N;
	scanf("%d", &N);

	char command[6];

	for (int i = 0; i < N; i++) {
		scanf("%s", command);

		if (!strcmp(command, "push")) {
			int temp;
			scanf("%d", &temp);
			push(temp);
		}
		else if (!strcmp(command, "pop")) {
			printf("%d\n", pop());
		}
		else if (!strcmp(command, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(command, "empty")) {
			printf("%d\n", empty());
		}
		else if (!strcmp(command, "top")) {
			printf("%d\n", top());
		}
	}
}

void push(int n) {
	if (ptr > STACK + STACK_SIZE - 1) return;
	else *++ptr = n;
	return;
}
int pop() {
	if (ptr < STACK) return -1;
	else return *ptr--;				// (*ptr)== 랑 *ptr-- 그만헷갈려!
}
int size() {
	return ptr - STACK+1;
}
bool empty() {
	if (ptr == STACK - 1) return true;
	else return false;
}
int top() {
	if (empty()) return -1;
	else return *ptr;
}

