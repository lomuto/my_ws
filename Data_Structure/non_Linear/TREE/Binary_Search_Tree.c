// problem with ROOT_NODE doesn't change

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLKSIZE 10
#define QUEUE_SIZE 100

struct node{
    int val;
    struct node* parent;
    struct node* left_child;    //struct node* left,right; 도 가능. 가독성위해 따로 씀
    struct node* right_child;
};

typedef struct node NODE;

NODE* root_ptr = NULL;  // initialize root_ptr to NULL

void INSERT(int n){
    NODE* node = malloc(sizeof(NODE));
    node->val = n;
    node->parent = NULL;
    node->left_child = NULL;
    node->right_child = NULL;
    if(root_ptr){   // goto else statement if root_ptr is NULL
        NODE* ptr;
        for(ptr = root_ptr ; ; ){ //break loop if one of left or right child is empty
            if(n == ptr->val){
                printf("OVERLAPPED VALUE\n");
                break;
            }
            else if(n < ptr->val){
                if(ptr->left_child == NULL){
                    node->parent = ptr;
                    ptr->left_child = node;     // "node = ptr->left" will make node to point NULL
                    break;
                }
                else
                    ptr = ptr->left_child;
            }
            else if(n > ptr->val)
                if(ptr->right_child == NULL){
                    node->parent = ptr;
                    ptr->right_child = node;
                    break;
                }
                else
                    ptr = ptr->right_child;
        }
    }
    else{
        root_ptr = node;
    }
}

void INORDER(NODE* node){
    if(node != NULL){
        INORDER(node->left_child);
        printf("%d ",node->val);
        INORDER(node->right_child);
    }
}

NODE* SEARCH(NODE* node,int target){
    if(target == node->val)
        return node;
    else if(target > node->val)
        return SEARCH(node->right_child,target);
    else if(target < node->val)
        return SEARCH(node->left_child,target);
    else
        return NULL;
}

NODE* SUCCESSOR(int value){
    NODE* node = SEARCH(root_ptr,value);

    if(node == NULL)
        return node;
    else if(node->right_child){  // if node has right subtree, then SUCCESSOR will be the very left child of right subtree
        for(node = node->right_child; node->left_child != NULL ;node = node->left_child)
            ;
        return node;
    }
    else{   // if node has no right subtree, keep search for parent node till meet root_node.
        for( ; node!=root_ptr ;node = node->parent){
            if(node->parent->left_child == node)    // Through that path to root node, if some node in that path is left_child of other node,
                return node->parent;                // then parent node of that left childed node is SUCESSOR
        }
        return NULL;
    }
}

int TREE_HEIGHT(){
    int count_left = 0;
    int count_right = 0;
    for(NODE* ptr = root_ptr; ptr != NULL ; ptr = ptr->left_child)
        count_left++;
    for(NODE* ptr = root_ptr; ptr != NULL ; ptr = ptr->right_child)
        count_right++;
    
    return count_left > count_right ? count_left : count_right;
}

void QUIT(NODE* node){
    if(node){
        QUIT(node->left_child);
        QUIT(node->right_child);
        free(node);
    }
}

int main(){
    char BUFFER[BLKSIZE+1];

    int temp;

    printf("[Enter \"q\" for exit]\n");
    printf("$");

    for(fgets(BUFFER,BLKSIZE+1,stdin);/*BUFFER[strlen(BUFFER)-1] = '\0'*/;fgets(BUFFER,BLKSIZE+1,stdin)){
        BUFFER[strlen(BUFFER)-1] = '\0';

        if(!strcmp(BUFFER,"INSERT")){
            printf("Enter a value of node to add: ");
            scanf("%d",&temp);
            while(getchar()!='\n');         //buffer clearing
            INSERT(temp);
        }
        else if(!strcmp(BUFFER,"INORDER")){
            INORDER(root_ptr);
            printf("\n");
        }
        /*else if(!strcmp(BUFFER,"REMOVE")){
            printf("Enter a number of node to remove: ");
            scanf("%d",&temp1);
            while(getchar()!='\n');         //buffer clearing
            REMOVE(head,temp1);
        }*/
        else if(!strcmp(BUFFER,"SEARCH")){
            printf("Enter a value of node to search: ");
            scanf("%d",&temp);
            while(getchar()!='\n');
            NODE* tar;
            if(tar = SEARCH(root_ptr,temp)){
                printf("Search Complete!\n");
                printf("target node's value is %d and its parent node's value is %d\n",tar->val,tar->parent->val);
            }
            else
                printf("Inexistence Value\n");
        }
        else if(!strcmp(BUFFER,"SUCCESSOR")){
            printf("Enter a value of node to find its successor: ");
            scanf("%d",&temp);
            while(getchar()!='\n');
            NODE* tar = SUCCESSOR(temp);
            if(tar == NULL)
                printf("Inexistence Value\n");
            else
                printf("Successor is %d\n",tar->val);
        }
        else if(!strcmp(BUFFER,"q")){
            QUIT(root_ptr);
            printf("Deallocated every node\n");
            return 0;
        }
        else
        {
            printf("Unavailable command. Try again\n");
        }

        printf("$");
    }

}