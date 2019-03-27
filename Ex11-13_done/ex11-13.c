
/*
// Ex 11
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <stdbool.h>
#define NAME_SIZE    256

// structure for one node in the linked list
typedef struct node_struct {
    int age;
    char name[NAME_SIZE];
    struct node_struct *next;
} Node;

// enumerated type for valid operations
typedef enum operation_enum {
    NEW = 1, FIND, DISPLAY_ASC, DISPLAY_DESC, QUIT
} Operation;

//
// function prototypes for the functions the students need to create
//

void insert_node(Node **head_ptr, Node *node);
Node *find_node(Node *head, const int age);
void display_node(Node *node);
void display_list(Node *head, Operation op);


Node *new_node(const int age, const char *name)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) {
        fprintf(stderr, "Unable to create new node\n");
        return NULL;
    }
    new->age = age;
    strncpy(new->name, name, NAME_SIZE);
    new->next = NULL;
    return new;
}

void insert_node(Node **head_ptr, Node *node)
{
    Node * element;
    if (*head_ptr == NULL || (*head_ptr)->age >= node->age)
    {
        node->next = *head_ptr;
        *head_ptr = node;
    }
    else
    {
        element = *head_ptr;
        while (element->next != NULL && element->next->age < node->age)
        {
            element = element->next;
        }
        node->next = element->next;
        element->next = node;
    }
}

Node *find_node(Node *head, const int age){
    if(head == NULL) return NULL;
    if(head->age == age) return head;
    return find_node(head->next, age);
}

void display_node(Node *node)
{
    printf("The %s is %d old", node->name, node->age);
    printf("\n");
}


void display_list(Node *head, Operation op)
{
    if(op == DISPLAY_ASC)
    {
        Node * element = head;
        while (element != NULL) {
            printf("The %s is %d old \n", element->name, element->age);
            element = element->next;
        }
    }
    else {
        Node * element = head;
        if(element->next != NULL)
            display_list(element->next, op);
        printf("The %s is %d old",element->name, element->age);
    }
    printf("\n");
}


bool get_operation(Operation *operation, int *age, char *name)
{
    const char prompt[] = "Enter an option:\n\t1) Add node\n\t2) Find node\n\t3) display ascending\n\t4) display descending\n\t5) Quit\n-> ";
    char input[NAME_SIZE];

    bool invalid_operation = true;
    while (invalid_operation) {

        fprintf(stdout, prompt);

        // get the option number from the user's input
        int op;
        if (fgets(input, NAME_SIZE, stdin) && sscanf(input, "%d", &op) == 1) {
            *operation = op;
            switch(op) {
                case NEW:
                    // Need both age and name
                    fprintf(stdout, "Age: ");
                    if (!fgets(input, NAME_SIZE, stdin) || sscanf(input, "%d", age) != 1) {
                        fprintf(stdout, "Age must be an integer\n");
                        break;
                    }
                    fprintf(stdout, "Name: ");
                    if (!fgets(name, NAME_SIZE, stdin)) {
                        fprintf(stderr, "Error reading name from stdin\n");
                        break;
                    }
                    invalid_operation = false;
                    break;

                case FIND:
                    // Only need age
                    fprintf(stdout, "Age: ");
                    if (!fgets(input, NAME_SIZE, stdin) || sscanf(input, "%d", age) != 1) {
                        fprintf(stdout, "Age must be an integer\n");
                        break;
                    }
                    invalid_operation = false;
                    break;

                case DISPLAY_ASC:
                case DISPLAY_DESC:
                    // no additional information needed
                    invalid_operation = false;
                    break;

                case QUIT:
                    return true;

                default:
                    fprintf(stdout, "Invalid option\n\n");
                    break;
            } // end switch
        } else {
            fprintf(stdout, "Invalid option\n");
        }
    } // end while

    return false;
}


int main(void) {
    Node *head = NULL;        // pointer to the first node in the linked list
    Node *node;
    Operation op;
    int age;
    char name[NAME_SIZE];

    while (!get_operation(&op, &age, name)) {

        switch (op) {
            case NEW:
                // Create a new node and insert it into the list
                node = new_node(age, name);
                insert_node(&head, node);
                break;

            case FIND:
                // Display all nodes containing the specified age
                node = find_node(head, age);
                while (node && node->age == age) {
                    display_node(node);
                    node = node->next;
                    node = find_node(node, age);
                }
                break;

            case DISPLAY_ASC:
            case DISPLAY_DESC:
                // Display the entire linked list in the specified order
                display_list(head, op);
                break;

            case QUIT:
                return 0;

            default:
                break;
        } // end switch
    } // end while

    return 1;
}
*/
// Ex 12-13

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NAME_SIZE    256

typedef struct node_struct {
    int age;
    char name[NAME_SIZE];
    struct node_struct *next;
    struct node_struct * prev;
} Node;

typedef enum operation_enum {
    NEW = 1, FIND, DISPLAY_ASC, DISPLAY_DESC, REMOVE, QUIT
} Operation;


void insert_node(Node **head_ptr, Node *node);
Node *find_node(Node *head, const int age);
void display_node(Node *node);
void display_list(Node *head, Operation op);
void deleteNode(Node** head_ptr, Node* del);

Node *new_node(const int age, const char *name)
{
    Node *new = (Node *)malloc(sizeof(Node));
    if (!new) {
        fprintf(stderr, "Unable to allocate memory for new node\n");
        return NULL;
    }

    new->age = age;
    strncpy(new->name, name, NAME_SIZE);
    new->prev = NULL;
    new->next = NULL;
    return new;
}

void insert_node(Node** head_ptr, Node* node)
{
    Node* element;

    if (*head_ptr == NULL)
        *head_ptr = node;

    else if ((*head_ptr)->age >= node->age) {
        node->next = *head_ptr;
        node->next->prev = node;
        *head_ptr = node;
    }

    else {
        element = *head_ptr;

        while (element->next != NULL &&
               element->next->age < node->age)
            element = element->next;

        node->next = element->next;

        if (element->next != NULL)
            node->next->prev = node;

        element->next = node;
        node->prev = element;
    }
}

Node *find_node(Node *head, const int age)
{
    if(head == NULL) return NULL;
    if(head->age == age) return head;
    return find_node(head->next, age);
}

void display_node(Node *node)
{
    printf("The %s is %d old", node->name, node->age);
    printf("\n");
}

void display_list(Node *head, Operation op)
{
    if(op == DISPLAY_ASC)
    {
        Node * element = head;
        while (element != NULL) {
            printf("The %s is %d old \n", element->name, element->age);
            element = element->next;
        }
    }
    else {
        Node * element = head;
        while(element->next != NULL)
        {
            element = element->next;
        }
        while(element != NULL)
        {
            printf("The %s is %d old \n",element->name, element->age);
            element = element->prev;
        }
    }
    printf("\n");
}

void deleteNode(Node** head_ptr, Node* del)
{
    if (*head_ptr == NULL || del == NULL)
        return;

    if (*head_ptr == del)
        *head_ptr = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}


bool get_operation(Operation *operation, int *age, char *name)
{
    const char prompt[] = "Enter an option:\n\t1) Add node\n\t2) Find node\n\t3) display ascending\n\t4) display descending\n\t5) Remove \n\t6) Quit\n-> ";
    char input[NAME_SIZE];

    bool invalid_operation = true;
    while (invalid_operation) {

        fprintf(stdout, prompt);

        // get the option number from the user's input
        int op;
        if (fgets(input, NAME_SIZE, stdin) && sscanf(input, "%d", &op) == 1) {
            *operation = op;
            switch(op) {
                case NEW:
                    // Need both age and name
                    fprintf(stdout, "Age: ");
                    if (!fgets(input, NAME_SIZE, stdin) || sscanf(input, "%d", age) != 1) {
                        fprintf(stdout, "Age must be an integer\n");
                        break;
                    }
                    fprintf(stdout, "Name: ");
                    if (!fgets(name, NAME_SIZE, stdin)) {
                        fprintf(stderr, "Error reading name from stdin\n");
                        break;
                    }
                    invalid_operation = false;
                    break;

                case FIND:
                    // Only need age
                    fprintf(stdout, "Age: ");
                    if (!fgets(input, NAME_SIZE, stdin) || sscanf(input, "%d", age) != 1) {
                        fprintf(stdout, "Age must be an integer\n");
                        break;
                    }
                    invalid_operation = false;
                    break;

                case DISPLAY_ASC:
                case DISPLAY_DESC:
                    // no additional information needed
                    invalid_operation = false;
                    break;
                case REMOVE:
                    fprintf(stdout, "Age: ");
                    if (!fgets(input, NAME_SIZE, stdin) || sscanf(input, "%d", age) != 1) {
                        fprintf(stdout, "Age must be an integer\n");
                        break;
                    }
                    invalid_operation = false;
                    break;
                case QUIT:
                    return true;

                default:
                    fprintf(stdout, "Invalid option\n\n");
                    break;
            } // end switch
        } else {
            fprintf(stdout, "Invalid option\n");
        }
    } // end while

    return false;
}

int main(void)
{
    Node *head = NULL;        // pointer to the first node in the linked list
    Node *node;
    Operation op;
    int age;
    char name[NAME_SIZE];

    while (!get_operation(&op, &age, name)) {

        switch(op) {
            case NEW:
                // Create a new node and insert it into the list
                node = new_node(age, name);
                insert_node(&head, node);
                break;

            case FIND:
                // Display all nodes containing the specified age
                node = find_node(head, age);
                while(node && node->age == age) {
                    display_node(node);
                    node = node->next;
                    node = find_node(node, age);
                }
                break;

            case DISPLAY_ASC:
            case DISPLAY_DESC:
                // Display the entire linked list in the specified order
                display_list(head, op);
                break;
            case REMOVE:
                node = find_node(head, age);
                deleteNode(&head, node);
                break;
            case QUIT:
                return 0;

            default: break;        // don't need, but here to avoid compiler warning
        } // end switch
    } // end while

    // if we get here, it's because there was an error reading input
    return 1;
}

