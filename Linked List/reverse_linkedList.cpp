#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
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

void reverseByVector(Node* &head) {
    vector<int> v;
    Node* curr = head;

    while(curr != NULL) {
        v.push_back(curr -> data);
        curr = curr -> next;
    }

    reverse(v.begin(), v.end());

    curr = head;
    int i = 0;
    while(curr != NULL) {
        curr -> data = v[i];
        i++;
        curr = curr -> next;
    }
}

void reverseByStack(Node* &head) {
    stack<int> st;
    Node* curr = head;

    while(curr != NULL) {
        st.push(curr -> data);
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

void reverseByLoop(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* ptr = NULL;

    while(curr != NULL) {
        ptr = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = ptr;
    }

    head = prev;
}

void solve(Node* &head, Node* &curr, Node* &prev) {
    if(curr == NULL) {
        head = prev;
        return ;
    }

    solve(head, curr -> next, curr);
    curr -> next = prev;
}

void reverseByRecursion(Node* &head) {
    Node* curr = head;
    Node* prev = NULL;

    solve(head, curr, prev);
}

int main(){
    Node* head = new Node(1);

    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    printLinkedList(head);

    // Approach 1
    reverseByVector(head);
    printLinkedList(head);

    // Approach 2
    reverseByStack(head);
    printLinkedList(head);

    // Approach 3
    reverseByLoop(head);
    printLinkedList(head);

    // Approach 4
    reverseByRecursion(head);
    printLinkedList(head);

    return 0;
}