#include <stdio.h>
#include <stdlib.h>

struct queue {
    int value;
    struct queue *next;
};
struct queue *front, *rear;
int i,j,n,ch=0;

void enqueue() {
    int x;
    struct queue *ptr = (struct queue*)malloc(sizeof(struct queue));
    if(ptr==NULL) {
        printf("stack is overflow. \n");
    }
    else {
        printf("enter a value to be pushed: ");
        scanf("%d",&x);
        ptr->value=x;
        if(front==NULL) {
            front=ptr;
            front->next=NULL;
        }
        else {
            rear->next=ptr;
        }
        rear=ptr;
        rear->next=NULL;
        printf("the pushed element is %d \n", ptr->value);
    }
}

void dequeue() {
    struct queue *ptr;
    if(front==NULL) {
        printf("queue is underflow. \n");
    }
    else {
        printf("the popped elements is %d \n",front->value);
        ptr=front;
        front=front->next;
    }
}

void display() {
    struct queue *ptr;
    if(front==NULL) {
        printf("the queue is empty. \n");
    }
    else {
        ptr=front;
        printf("the elements in queue is: ");
        while(ptr!=NULL) {
            printf("%d ",ptr->value);
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
        printf("enter 3 to display the queue. \n");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        if(ch==1) {
            enqueue();
        }
        else if (ch==2) {
            dequeue();
        }
        else if (ch==3) {
            display();
        }
        else {
            break;
        }
    }
}
