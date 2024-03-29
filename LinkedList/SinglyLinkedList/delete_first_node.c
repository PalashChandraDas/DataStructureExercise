#include<stdio.h>
typedef struct node Node; //struct node = Node
struct node {
    int data; //data part of node
    Node *next; //address part of node
} *head; //name of the structure type variable

//create node
void createNodeList(int n) {
    Node *current_node, *new_node;
    int num, i;
    
    head = (Node *)malloc(sizeof(Node)); //memory allocate for first node
    if(head == NULL) {
        printf("Error! Couldn't create a new node.\n");
    }
    printf("Input the data of node 1: ");
    scanf("%d", &num);
    head->data = num;
    head->next = NULL;
    current_node = head; //pass the address of first node in current_node

    //create 2nd to n node
    for(i = 2; i <= n; i++) {
        int num;
        new_node = (Node *)malloc(sizeof(Node)); //memory allocate for next node
        if(new_node == NULL) {
            printf("Error! Couldn't create a node.\n");
            break;
        } else {
            printf("Enter the data of node %d: ", i);
            scanf("%d", &num);
            new_node->data = num;
            new_node->next = NULL;
            current_node->next = new_node; //links previous node
            current_node = current_node->next;
        }
    }

}

//Delete first node of Linked List
void firstNodeDeletion() {
    Node *del_node;

    if(head == NULL) {
        printf("There are no node in the list.\n");
    } else {
        del_node = head;
        head = head->next;
        printf("delete data of node 1 = %d\n", del_node->data);
        free(del_node); //Clears the memory occupied by first node
    }

}

//display list
void print_linked_list() {
    Node *current_node;
    if(head == NULL) {
        printf("No data found in the empty list.\n");
    } else {
        current_node = head;
        while(current_node != NULL) {
            printf("Data = %d\n", current_node->data); // prints the data of current node
            current_node = current_node->next; // advances the position of current node
        }
    }
}

int main() {
    int n, num;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createNodeList(n);

    printf("\nData entered in the Linked List are:\n");
    print_linked_list();

    firstNodeDeletion();
    printf("\nData, after deletion of first node:\n");
    print_linked_list();

    return 0;
}
