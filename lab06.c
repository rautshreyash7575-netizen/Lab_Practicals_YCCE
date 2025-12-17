#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (!root) return createNode(value);
    if (value < root->data) root->left = insert(root->left, value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (!root || root->data == key) return root;
    return (key < root->data) ? search(root->left, key) : search(root->right, key);
}

int isLeaf(struct Node* node) {
    return node && !node->left && !node->right;
}

struct Node* deleteLeaf(struct Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data) root->left = deleteLeaf(root->left, key);
    else if (key > root->data) root->right = deleteLeaf(root->right, key);
    else if (isLeaf(root)) {
        printf("Deleting leaf node: %d\n", root->data);
        free(root);
        return NULL;
    } else {
        printf("Node %d is not a leaf, cannot delete.\n", key);
    }
    return root;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* res;

    while(1) {
        printf("\n1. Search  2. Insert  3. Delete Leaf  4. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice == 1) {
            printf("Enter element to search: ");
            scanf("%d",&value);
            res = search(root,value);
            printf(res ? "Found\n" : "Not Found\n");
        } else if(choice == 2) {
            printf("Enter element to insert: ");
            scanf("%d",&value);
            root = insert(root,value);
            printf("Inserted %d\nInorder: ", value);
            inorder(root);
            printf("\n");
        } else if(choice == 3) {
            printf("Enter leaf element to delete: ");
            scanf("%d",&value);
            root = deleteLeaf(root,value);
            printf("Inorder: ");
            inorder(root);
            printf("\n");
        } else if(choice == 4) {
            printf("Exit\n");
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

