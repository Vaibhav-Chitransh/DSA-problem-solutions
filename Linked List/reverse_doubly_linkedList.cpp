#include <iostream>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printLinkedList(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&head, int data)
{
    Node *nodeToInsert = new Node(data);

    Node *curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = nodeToInsert;
    nodeToInsert->prev = curr;
}

void reverseByStack(Node* &head) {
    stack<int> st;
    Node* curr = head;

    while(curr != NULL) {
        int d = curr -> data;
        st.push(d);
        curr = curr -> next;
    }

    curr = head;

    while(curr != NULL) {
        int d = st.top();
        curr -> data = d;
        st.pop();
        curr = curr -> next;
    }
}

void reverse(Node* &head) {
    Node* curr = head;
    Node* temp = NULL;

    while(curr != NULL) {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }

    head = temp -> prev;
}

int main() {
    Node* head = new Node(1);

    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);

    printLinkedList(head);

    // Approach 1
    reverseByStack(head);
    printLinkedList(head);

    // Approach 2
    reverse(head);
    printLinkedList(head);

    return 0;
}