#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int isLeaf(struct Node* node) {
    return (node->left == NULL && node->right == NULL);
}

struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if (isLeaf(root)) {
            printf("Deleting leaf node: %d\n", root->data);
            free(root);
            return NULL;
        } else {
            printf("Node %d is not a leaf node, cannot delete.\n", key);
        }
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* result;

    while(1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Search\n");
        printf("2. Insert\n");
        printf("3. Delete Leaf\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice) {
        case 1:
            printf("Enter element to search: ");
            scanf("%d",&value);
            result = search(root,value);
            if(result != NULL)
                printf("Found\n");
            else
                printf("NULL\n");
            break;

        case 2:
            printf("Enter element to insert: ");
            scanf("%d",&value);
            root = insert(root,value);
            printf("Inserted %d\n",value);
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Enter leaf element to delete: ");
            scanf("%d",&value);
            root = deleteLeaf(root,value);
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("Exit\n");
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
