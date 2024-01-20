#include <stdio.h>

int stack[100],i,n,ch=0,top=-1;

void push() {
    int x;
    if(top==n) {
        printf("stack is overflow. \n");
    }
    else {
        printf("enter a value to be pushed: ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
        printf("the pushed element is %d \n",stack[top]);
    }
}

void pop() {
    if(top==-1) {
        printf("stack is under flow. \n");
    }
    else {
        printf("the popped elements is %d \n",stack[top]);
        top--;
    }
}

void display() {
    if(top==-1) {
        printf("the stack is empty. \n");
    }
    else {
        printf("the elements in stack is: \n");
        for(i=top; i>=0; i--) {
            printf("%d \n", stack[i]);
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
