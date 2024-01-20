#include <stdio.h>

int queue[100],i,n,ch=0,front=-1,rear=-1;

void enqueue() {
    int x;
    if(rear==n-1) {
        printf("queue is overflow. \n");
    }
    else {
        printf("enter a value to be inserted: ");
        scanf("%d",&x);
        if(front==-1 && rear==-1) {
            front=0;
            rear=0;
        }
        else {
            rear++;
        }
        queue[rear]=x;
        printf("the inserted value is %d \n",queue[rear]);
    }
}

void dequeue() {
    if(front==-1 || front>rear) {
        printf("queue is underflow. \n");
    }
    else {
        printf("the deleted value is %d \n",queue[front]);
        if(front==rear) {
            front=-1;
            rear=-1;
        }
        else {
            front++;
        }
    }
}

void display() {
    if(rear==-1) {
        printf("the queue is empty. \n");
    }
    else {
        printf("the element in queue is: ");
        for(i=front; i<=rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main () {
    printf("enter number of elements: ");
    scanf("%d",&n);
    while(ch!=-1) {
        printf("\nenter 1 to insert an element. \n");
        printf("enter 2 to delete an element. \n");
        printf("enter 3 to display the stack. \n");
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
