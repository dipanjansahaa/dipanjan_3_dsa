#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorderTraversal(struct node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->key);
    inorderTraversal(root->right);
}

void preorderTraversal(struct node* root) {
    if (root == NULL)
        return;
    printf("%d ->", root->key);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->key);
}

struct node *insertNode(struct node *node, int key) {
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else
        node->right = insertNode(node->right, key);
    return node;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
    		struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
    		struct node *temp = root->left;
            free(root);
            return temp;
        }
    	struct node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    struct node *root = NULL;
    int n,n1,i,ch=-2;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        printf("enter element: ");
        scanf("%d",&n1);
        root = insertNode(root, n1);
    }
    while(ch!=-1) {
        printf("\n");
        printf("for insert node, press 1\n");
        printf("for delete node, press 2\n");
        printf("for inorder traversal, press 3\n");
        printf("for preorder traversal, press 4\n");
        printf("for postorder traversal, press 5\n");
        printf("enter your choice: ");
        scanf("%d",&ch);
        if(ch==1) {
            printf("enter element to insert: ");
            scanf("%d",&n1);
            root = insertNode(root, n1);
            printf("%d is inserted\n",n1);
        }
        else if(ch==2) {
            printf("enter element to delete: ");
            scanf("%d",&n1);
            root = deleteNode(root, n1);
            printf("%d is deleted\n",n1);
        }
        else if(ch==3) {
            printf("inorder traversal of the tree is: ");
            inorderTraversal(root);
            printf("\n");
        }
        else if(ch==4) {
            printf("preorder traversal of the tree is: ");
            preorderTraversal(root);
            printf("\n");
        }
        else if(ch==5) {
            printf("postorder traversal of the tree is: ");
            postorderTraversal(root);
            printf("\n");
        }
        else {
            break;
        }
    }
    return 0;
}
