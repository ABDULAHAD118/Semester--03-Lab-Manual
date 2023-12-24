#include <iostream>
using namespace std;
void reverseList();
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert(int new_data)
{
    struct Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void display()
{
    struct Node *ptr;
    ptr = head;
    cout << "[";
    while (ptr != NULL)
    {
        cout << "\t" << ptr->data;
        ptr = ptr->next;
    }
    cout << "\t]";
}

void deleteValue(int valueToDelete)
{
    Node *current = head;
    Node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == valueToDelete)
        {

            if (prev == NULL)
            {

                head = current->next;
                delete current;
                return;
            }
            else
            {

                prev->next = current->next;
                delete current;
                return;
            }
        }

        prev = current;
        current = current->next;
    }

    cout << "Value not found in the list." << endl;
}

int main()
{
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);
    cout << "The linked list is: ";
    display();
    reverseList();
    cout << "\nThe linked list is: ";
    display();
    deleteValue(9);
    cout << "\nThe linked list after delete 9  is: ";
    display();
    return 0;
}

int length()
{
    Node *p;
    int len;
    p = head;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

void reverseList() {
    if (head == NULL) {
        // If the list is empty, there's nothing to reverse.
        return;
    }

    Node* current = head;
    Node* prev = NULL;
    
    while (current != NULL) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // Update the head to point to the last node (which was the first node after reversing).
    head = prev;
}

