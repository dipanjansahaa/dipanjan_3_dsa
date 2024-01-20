#include <stdio.h>

int queue[100],i,n,ch=0,front=-1,rear=-1;

void push() {
    int x;
    if ((front == rear + 1) || (front == 0 && rear == n - 1))
        printf("queue is overflow. \n");
    else {
        printf("enter a value to be pushed: ");
        scanf("%d",&x);
        if (front == -1)
            front = 0;
        rear = (rear + 1) % n;
        queue[rear] = x;
        printf("the pushed element is %d \n", queue[rear]);
    }
}

void pop() {
    if (front==-1) {
        printf("queue is underflow. \n");
    }
    else {
        printf("the popped element is %d \n",queue[front]);
        if (front==rear) {
            front=-1;
            rear=-1;
        }
        else {
            front = (front+1)%n;
        }
    }
}

void display() {
    if (front==-1)
        printf("the queue is empty. \n");
    else {
        printf("the element in queue is: ");
        for (i=front; i!=rear; i=(i+1)%n) {
            printf("%d ", queue[i]);
        }
        printf("%d \n", queue[i]);
    }
}

void main() {
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
