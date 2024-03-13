#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        // Constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
};

void print(Node* refNode) {
    Node* temp = refNode;
    cout << temp -> data << " -> ";
    temp = temp -> next;

    while(temp != refNode) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << endl;
}

void insertNode(Node* &refNode, int data, int nodeData) {
    Node* nodeToInsert = new Node(nodeData);

    Node* curr = refNode;

    while(curr -> data != data) {
        curr = curr -> next;
    }

    nodeToInsert -> next = curr -> next;
    curr -> next = nodeToInsert;
}

void reverse(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* temp = NULL;

    do {
        temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    } while(curr != head);

    // head update
    head -> next = prev;
    head = prev;
}

int main(){
    Node* refNode = new Node(1);
    refNode -> next = refNode;

    // Insertion
    insertNode(refNode, 1, 2);

    insertNode(refNode, 2, 3);
    insertNode(refNode, 3, 4);
    insertNode(refNode, 4, 5);

    print(refNode);

    reverse(refNode);
    print(refNode);

    return 0;
}