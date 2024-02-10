#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = head;
    head = nodeToInsert;
}

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

void insertAtTail(Node* &head, int data) {
    Node* nodeToInsert = new Node(data);

    Node* curr = head;

    while(curr -> next != NULL) {
        curr = curr -> next;
    }

    curr -> next = nodeToInsert;
}

void insertAtPosition(Node* &head, int data, int k) {
    Node* nodeToInsert = new Node(data);

    Node* curr = head;

    while(k > 2) {
        curr = curr -> next;
        k--;
    }

    nodeToInsert -> next = curr -> next;
    curr -> next = nodeToInsert;
}

void deleteHeadNode(Node* &head) {
    Node* nodeToDelete = head;

    head = nodeToDelete -> next;
    nodeToDelete -> next = NULL;
    delete(nodeToDelete);
}

void deleteNodeAtPosition(Node* &head, int k) {
    Node* nodeToDelete = head;
    Node* curr = NULL;

    while(k > 1) {
        curr = nodeToDelete;
        nodeToDelete = nodeToDelete -> next;
        k--;
    }

    curr -> next = nodeToDelete -> next;
    nodeToDelete -> next = NULL;
    delete(nodeToDelete);
}

int main()
{
    Node *head = new Node(2);

    // cout << head -> data << endl;
    // cout << head -> next << endl;

    // Insertion

    // 1. Insert at head
    insertAtHead(head, 9);
    printLinkedList(head);

    // 2. Insert at Tail 
    insertAtTail(head, 7);
    printLinkedList(head);

    // 3. Insert at a position k 
    insertAtPosition(head, 5, 2);
    printLinkedList(head);

    // Deletion

    // 1. Delete the head node 
    deleteHeadNode(head);
    printLinkedList(head);

    // 2. Delete Node at position k 
    insertAtTail(head, 3);
    printLinkedList(head);

    deleteNodeAtPosition(head, 3);
    printLinkedList(head);

    deleteNodeAtPosition(head, 3);
    printLinkedList(head);

    return 0;
}