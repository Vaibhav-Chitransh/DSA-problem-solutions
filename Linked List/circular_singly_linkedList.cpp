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

void deleteNode(Node* &refNode, int data) {
    Node* nodeToDelete = refNode;
    Node* curr = NULL;

    while(nodeToDelete -> data != data) {
        curr = nodeToDelete;
        nodeToDelete = nodeToDelete -> next;
    }

    curr -> next = nodeToDelete -> next;
    nodeToDelete -> next = NULL;
    delete(nodeToDelete);
}

int main(){
    Node* refNode = new Node(1);
    refNode -> next = refNode;

    print(refNode);

    // Insertion
    insertNode(refNode, 1, 2);
    print(refNode);

    insertNode(refNode, 2, 3);
    insertNode(refNode, 3, 4);
    insertNode(refNode, 4, 5);

    print(refNode);

    // Deletion
    deleteNode(refNode, 3);
    print(refNode);

    deleteNode(refNode, 7);
    print(refNode);

    return 0;
}