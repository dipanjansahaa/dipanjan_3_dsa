#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *head, *tail;

void create_Node(int new) {
    struct node *newnode;
    int n, i;
    for(i=0; i<new; i++) {
        printf("enter data for node %d: ",i+1);
        scanf("%d", &n);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->value = n;
        newnode->next = NULL;
        if(head == NULL) {
            head = newnode;
            newnode->next = head;
            tail = head;
        }
        else{
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
    }
}

void add_begin_Node(int add) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newNode->value = add;
    while(temp->next != head) {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void add_end_Node(int add) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newNode->value = add;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void add_middle_Node(int add, int pos_Node) {
    int i;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = add;
    struct node *pos = head;
    for(i=0; i<pos_Node-2; i++) {
        if(pos->next != NULL) {
            pos = pos->next;
        }
    }
    newNode->next = pos->next;
    pos->next = newNode;
}

void delete_begin_Node() {
    struct node *temp = head;
    if(head->next == head) {
        head = NULL;
    }
    else{
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        head = temp->next;
    }
}

void delete_end_Node() {
    struct node *temp = head;
    if(head->next == head) {
        head = NULL;
    }
    else{
        while(temp->next->next != head) {
            temp = temp->next;
        }
        temp->next = head;
    }
}

void delete_middle_Node(int pos_Node) {
    int i;
    struct node *del = head;
    for(i=0; i<pos_Node-2; i++) {
        if(del->next != NULL) {
            del = del->next;
        }
    }
    del->next = del->next->next;
}

void display_Node() {
    int i=0;
    struct node *temp = head;
    if(temp == NULL) {
        printf("list is empty. \n");
    }
    else{
        printf("data entered in the list: \n");
        while(temp->next != head) {
            printf("entered data for node %d: %d \n", i+1, temp->value);
            temp = temp->next;
            i++;
        }
        printf("entered data for node %d: %d \n", i+1, temp->value);
    }
}

int main() {
    int new, ch=0, add, pos_Node;
    printf("enter number of nodes: ");
    scanf("%d",&new);
    create_Node(new);
    display_Node();
    while(ch!=-1) {
        printf("\nenter 1 to insert an element at the beginning. \n");
        printf("enter 2 to insert an element at the end. \n");
        printf("enter 3 to insert an element at a specific position. \n");
        printf("enter 4 to delete an element from the beginning. \n");
        printf("enter 5 to delete an element from the end. \n");
        printf("enter 6 to delete an element from a specific position. \n");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
        if(ch==1) {
            printf("enter data: ");
            scanf("%d",&add);
            add_begin_Node(add);
            printf("after adding node at the beginning, ");
            display_Node();
        }
        else if(ch==2) {
            printf("enter data: ");
            scanf("%d",&add);
            add_end_Node(add);
            printf("after adding node at the end, ");
            display_Node();
        }
        else if(ch==3) {
            printf("enter data: ");
            scanf("%d",&add);
            printf("enter position: ");
            scanf("%d",&pos_Node);
            add_middle_Node(add,pos_Node);
            printf("after adding node at a specific position, ");
            display_Node();
        }
        else if(ch==4) {
            delete_begin_Node();
            printf("after deleting node from the beginning, ");
            display_Node();
        }
        else if(ch==5) {
            delete_end_Node();
            printf("after deleting node from the end, ");
            display_Node();
        }
        else if(ch==6) {
            printf("enter position: ");
            scanf("%d",&pos_Node);
            delete_middle_Node(pos_Node);
            printf("after deleting node from a specific position, ");
            display_Node();
        }
        else {
            break;
        }
    }
    return 0;
}
