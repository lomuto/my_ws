/*
	a
       /|\
      / | \
     b	c  d
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node** child;    // array of NODE pointers
};

typedef struct node NODE;

int main(){
    NODE a;
    NODE b;
    NODE c;
    NODE d;

    a.val = 1;
    b.val = 2;
    c.val = 3;
    d.val = 4;

    a.child = (NODE**)malloc(3*sizeof(NODE*));  //a will point 3 childs:b,c,d
    *(a.child) = &b;
    *(a.child+1) = &c;
    *(a.child+2) = &d;

    printf("%d %d %d\n",(**(a.child)).val,(**(a.child+1)).val,(**(a.child+2)).val); // operator precedence: '.' is prior then '*'
}
