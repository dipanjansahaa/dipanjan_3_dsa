#include <stdio.h>
#include <stdlib.h>

struct node {
    int key, height;
    struct node *left, *right;
};

int height(struct node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

struct node *newNode(int key) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct node *N) {
    if (N == NULL)
        return 0;
    return (height(N->left) - height(N->right));
}

struct node *insertNode(struct node *node, int key) {
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
    while (current->left != NULL)
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
        if ((root->left == NULL) || (root->right == NULL)) {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else {
            struct node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
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
