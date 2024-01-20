#include <stdio.h>
#include <stdlib.h>

struct stack {
    int value;
    struct stack *next;
};
struct stack *top;
int i,j,n,ch=0;

void push() {
    int x;
    struct stack *ptr = (struct stack*)malloc(sizeof(struct stack));
    if(ptr==NULL) {
        printf("stack is overflow. \n");
    }
    else {
        printf("enter a value to be pushed: ");
        scanf("%d",&x);
        ptr->value=x;
        if(top==NULL) {
            ptr->next=NULL;
        }
        else {
            ptr->next=top;
        }
        top=ptr;
        printf("the pushed element is %d \n", ptr->value);
    }
}

void pop() {
    struct stack *ptr;
    if(top==NULL) {
        printf("stack is under flow. \n");
    }
    else {
        printf("the popped elements is %d \n",top->value);
        ptr=top;
        top=top->next;
    }
}

void display() {
    struct stack *ptr;
    if(top==NULL) {
        printf("the stack is empty. \n");
    }
    else {
        ptr=top;
        printf("the elements in stack is: \n");
        while(ptr!=NULL) {
            printf("%d \n",ptr->value);
            ptr=ptr->next;
        }
    }
}

void main () {
    printf("enter number of elements: ");
    scanf("%d",&n);
    while(ch!=-1) {
        printf("\nenter 1 to push an element. \n");
        printf("enter 2 to pop an element. \n");
        printf("enter 3 to display the stack. \n");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        if(ch==1) {
            push();
        }
        else if (ch==2) {
            pop();
        }
        else if (ch==3) {
            display();
        }
        else {
            break;
        }
    }
}
