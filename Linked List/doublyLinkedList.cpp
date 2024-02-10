#include <iostream>
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

void insertAtHead(Node *&head, int data)
{
    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = head;
    head->prev = nodeToInsert;
    head = nodeToInsert;
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

void insertAtPosition(Node* &head, int data, int k) {
    Node* nodeToInsert = new Node(data);

    Node* curr = head;

    while(k > 2) {
        curr = curr -> next;
        k--;
    }

    // Ordering matters
    nodeToInsert -> prev = curr;
    curr -> next -> prev = nodeToInsert;
    nodeToInsert -> next = curr -> next;
    curr -> next = nodeToInsert;
}

void deleteHead(Node* &head) {
    Node* nodeToDelete = head;

    head -> next -> prev = NULL;
    head = head -> next;
    nodeToDelete -> next = NULL;

    delete(nodeToDelete);
}

void deleteTail(Node* &head) {
    Node* nodeToDelete = head;

    while(nodeToDelete -> next != NULL) {
        nodeToDelete = nodeToDelete -> next;
    }

    nodeToDelete -> prev -> next = NULL;
    nodeToDelete -> prev = NULL;
    delete(nodeToDelete);
}

void deleteAtPosition(Node* &head, int k) {
    Node* nodeToDelete = head;

    while(k > 1) {
        nodeToDelete = nodeToDelete -> next;
        k--;
    }

    nodeToDelete -> next -> prev = nodeToDelete -> prev;
    nodeToDelete -> prev -> next = nodeToDelete -> next;
    nodeToDelete -> next = NULL;
    nodeToDelete -> prev = NULL;

    delete(nodeToDelete);
}

int main()
{
    Node *head = new Node(2);

    // cout << head -> data << endl;
    // cout << head -> next << endl;
    // cout << head -> prev << endl;

    // 1. Insert at head

    insertAtHead(head, 1);
    printLinkedList(head);

    // 2. Insert at tail

    insertAtTail(head, 3);
    printLinkedList(head);

    // 3. Insert at position (k=3) 

    insertAtPosition(head, 5, 3);
    printLinkedList(head);

    // 1. Delete the head node 

    deleteHead(head);
    printLinkedList(head);

    // 2. Delete the tail node 

    deleteTail(head);
    printLinkedList(head);

    // 3. Delete the node at any (k=3) position 
    insertAtTail(head, 7);
    insertAtTail(head, 9);
    printLinkedList(head);

    deleteAtPosition(head, 3);
    printLinkedList(head);
    
    return 0;
}