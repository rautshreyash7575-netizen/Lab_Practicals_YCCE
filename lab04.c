#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int num, count = 0;

    printf("Enter integers to add to the linked list (enter 0 to stop):\n");

    while (1) {
        scanf("%d", &num);
        if (num == 0)
            break;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
        count++;
    }

    printf("\nLinked List: ");
    temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("\nTotal number of nodes in the list: %d\n", count);

    return 0;
}
