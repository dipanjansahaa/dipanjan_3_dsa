# include<stdio.h>

int dequeue[100],n,left=-1,right=-1;

void insert_right() {
    int added_item;
    if((left==0 && right==n-1) || (left==right+1)) {
        printf("queue is overflow. \n");
        return;
    }
    if (left==-1) {
        left=0;
        right=0;
    }
    else if(right==n-1)
        right=0;
    else
        right=right+1;
    printf("enter a value to be pushed: ");
    scanf("%d", &added_item);
    dequeue[right]=added_item;
}

void insert_left() {
    int added_item;
    if((left==0 && right==n-1) || (left==right+1)) {
        printf("queue is overflow. \n");
        return;
    }
    if (left==-1) {
        left=0;
        right=0;
    }
    else if(left==0)
        left=n-1;
    else
        left=left-1;
    printf("enter a value to be pushed: ");
    scanf("%d", &added_item);
    dequeue[left]=added_item;
}

void delete_left() {
    if (left==-1) {
        printf("queue is underflow. \n");
        return;
    }
    printf("the popped element is %d \n",dequeue[left]);
    if(left==right) {
        left=-1;
        right=-1;
    }
    else if(left==n-1)
        left=0;
    else
        left=left+1;
}

void delete_right() {
    if (left==-1) {
        printf("queue is underflow. \n");
        return;
    }
    printf("the popped element is %d \n",dequeue[right]);
    if(left==right) {
        left=-1;
        right=-1;
    }
    else if(right == 0)
        right=n-1;
    else
        right=right-1;
}

void display_queue() {
    int front_pos=left, rear_pos=right;
    if(left==-1) {
        printf("queue is empty\n");
        return;
    }
    printf("queue elements: ");
    if (front_pos<=rear_pos) {
        while(front_pos<=rear_pos) {
            printf("%d ",dequeue[front_pos]);
            front_pos++;
        }
    }
    else {
        while(front_pos<=n-1) {
            printf("%d ",dequeue[front_pos]);
            front_pos++;
        }
        front_pos=0;
        while(front_pos<=rear_pos) {
            printf("%d ",dequeue[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

void input_que() {
    int choice;
    while(choice!=-1) {
        printf("\nenter 1 to insert at right.\n");
        printf("enter 2 to delete from left.\n");
        printf("enter 3 to delete from right.\n");
        printf("enter 4 to display.\n");
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        if (choice==1) {
            insert_right();
        }
        else if (choice==2) {
            delete_left();
        }
        else if (choice==3) {
            delete_right();
        }
        else if (choice==4) {
            display_queue();
        }
    }
}

void output_que() {
    int choice;
    while(choice!=-1) {
        printf("\nenter 1 to insert at left.\n");
        printf("enter 2 to insert from right.\n");
        printf("enter 3 to delete from leftt.\n");
        printf("enter 4 to display.\n");
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        if (choice==1) {
            insert_left();
        }
        else if (choice==2) {
            insert_right();
        }
        else if (choice==3) {
            delete_left();
        }
        else if (choice==4) {
            display_queue();
        }
    }
}

int main() {
    int choice;
    printf("\nenter 1 to follow input restricted dequeue\n");
    printf("enter 2 to follow output restricted dequeue\n");
    printf("\nenter your choice: ");
    scanf("%d",&choice);
    if (choice==1) {
        input_que();
    }
    else if (choice==2) {
        output_que();
    }
    return 0;
}
