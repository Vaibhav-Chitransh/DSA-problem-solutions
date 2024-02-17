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

void deleteNode(Node* &start, int data) {
    Node* nodeToDelete = start;

    while(nodeToDelete -> data != data) {
        nodeToDelete = nodeToDelete -> next;
    }

    nodeToDelete -> prev -> next = nodeToDelete -> next;
    nodeToDelete -> next -> prev = nodeToDelete -> prev;
    nodeToDelete -> next = NULL;
    nodeToDelete -> prev = NULL;

    delete(nodeToDelete);
}

int main(){
    Node* start = new Node(1);

    start -> prev = start;
    start -> next = start;

    // Insertion
    insertNode(start, 2, 1);
    print(start);

    insertNode(start, 3, 2);
    insertNode(start, 4, 3);
    insertNode(start, 6, 4);
    insertNode(start, 8, 3);
    print(start);

    // Deletion
    deleteNode(start, 4);
    print(start);

    deleteNode(start, 3);
    print(start);
    
    return 0;
}