#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
        Node* prev;

        // Constructor
        Node(int data) {
            this -> data = data;
            next = NULL;
            prev = NULL;
        }
};

void insertNode(Node* &start, int nodeData, int data) {
    Node* nodeToInsert = new Node(nodeData);
    Node* curr = start;

    while(curr -> data != data) {
        curr = curr -> next;
    }

    nodeToInsert -> next = curr -> next;
    curr -> next -> prev = nodeToInsert;
    curr -> next = nodeToInsert;
    nodeToInsert -> prev = curr;
}

void print(Node* start) {
    Node* curr = start;
    cout << curr -> data << " -> ";
    curr = curr -> next;

    while(curr != start) {
        cout << curr -> data << " -> ";
        curr = curr -> next;
    }cout << endl;
}

void reverse(Node* &head) {
    Node* curr = head;
    Node* temp = NULL;

    do {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    } while(curr != head);

    // head update
    head = temp -> prev;
}

int main(){
    Node* start = new Node(1);

    start -> prev = start;
    start -> next = start;

    // Insertion
    insertNode(start, 2, 1);

    insertNode(start, 3, 2);
    insertNode(start, 4, 3);
    insertNode(start, 6, 4);
    insertNode(start, 8, 3);
    print(start);

    reverse(start);
    print(start);

    return 0;
}