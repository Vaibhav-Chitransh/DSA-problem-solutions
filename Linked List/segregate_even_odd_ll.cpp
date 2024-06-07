/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 *		Node() : data(0), next(nullptr) {};
 *		Node(int x) : data(x), next(nullptr) {}
 *		Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

// Approach 1

Node* segregateEvenOdd(Node* head)
{
    vector<int> even;
    vector<int> odd;
    
    Node* curr = head;
    
    while(curr != NULL) {
        if(curr -> data % 2 == 0) even.push_back(curr -> data);
        else odd.push_back(curr -> data);
        curr = curr -> next;
    }
    
    curr = head;
    
    for(int i=0; i<even.size(); i++) {
        curr -> data = even[i];
        curr = curr -> next;
    }
    for(int i=0; i<odd.size(); i++) {
        curr -> data = odd[i];
        curr = curr -> next;
    }
    
    return head;
}

// Appraoch 2

Node* segregateEvenOdd(Node* head)
{
    if(head == NULL || head -> next == NULL) return head;

    Node* dummyEven = new Node(-1);
    Node* dummyOdd = new Node(-1);

    Node* even = dummyEven;
    Node* odd = dummyOdd;

    Node* curr = head;

    while(curr != NULL) {
        if(curr -> data % 2 == 0) {
            even -> next = curr;
            even = even -> next;
        }
        else {
            odd -> next = curr;
            odd = odd -> next;
        }

        curr = curr -> next;
    }

    even -> next = dummyOdd -> next;
    odd -> next = NULL;
    return dummyEven -> next;
}