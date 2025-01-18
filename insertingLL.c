#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node * insertAtBeginning(struct Node *head, int val){

    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return head;
    }
    newNode -> data = val;
    newNode -> next = head;
    return newNode;


}

void printList(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");

}
int main() {
    struct Node *head = NULL; // Initialize empty list
    int val;

    printf("Enter elements to insert at the beginning of the list (enter -1 to stop):\n");

    while (1) {
        printf("Enter value: ");
        scanf("%d", &val);

        if (val == -1) { // Stop taking input 
            break;
        }

        head = insertAtBeginning(head, val);   
    }

    printf("The linked list is: ");
    printList(head);

    
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}