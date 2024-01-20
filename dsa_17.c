#include <stdio.h>
#include <stdlib.h>

struct queue {
    int value;
    struct queue *next;
};
int ch=0;
struct queue *front, *rear;


void enqueue() {
    struct queue *ptr = (struct queue*)malloc(sizeof(struct queue));
    int x;
    printf("enter a value to be pushed: ");
    scanf("%d", &x);
    ptr->value = x;
    ptr->next = NULL;
    if(front == NULL) {
        front = ptr;
        ptr->next = front;
        rear = front;
    }
    else{
        rear->next = ptr;
        ptr->next = front;
        rear = ptr;
    }
    printf("the pushed element is %d \n", rear->value);
}

void dequeue() {
    struct queue *temp = front;
    if(front->next == front) {
        printf("the popped elements is %d \n",front->value);
        front = NULL;
    }
    else{
        while(temp->next != front){
            temp = temp->next;
        }
        printf("the popped elements is %d \n",temp->next->value);
        temp->next = front->next;
        front = temp->next;
    }
}

void display() {
    struct queue *temp = front;
    if(temp == NULL) {
        printf("queue is empty. \n");
    }
    else{
        printf("the element in queue is: ");
        while(temp->next != front) {
            printf("%d ", temp->value);
            temp = temp->next;
        }
        printf("%d \n", temp->value);
    }
}

void main() {
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
