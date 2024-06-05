/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// Approach 1

Node* sortList(Node *head){
    int zeroCnt = 0;
    int oneCnt = 0;
    int twoCnt = 0;

    Node* curr = head;

    while(curr != NULL) {
        if(curr -> data == 0) zeroCnt++;
        else if(curr -> data == 1) oneCnt++;
        else twoCnt++;
        curr = curr -> next;
    }

    curr = head;

    while(zeroCnt--) {
        curr -> data = 0;
        curr = curr -> next;
    }
    while(oneCnt--) {
        curr -> data = 1;
        curr = curr -> next;
    }
    while(twoCnt--) {
        curr -> data = 2;
        curr = curr -> next;
    }

    return head;
}

// Approach 2

Node* sortList(Node *head){
    Node* dummyZero = new Node(-1);
    Node* dummyOne = new Node(-1);
    Node* dummyTwo = new Node(-1);

    Node* zero = dummyZero;
    Node* one = dummyOne;
    Node* two = dummyTwo;

    Node* curr = head;

    while(curr != NULL) {  // O(n)
        if(curr -> data == 0) {
            zero -> next = curr;
            zero = zero -> next;
        }
        else if(curr -> data == 1) {
            one -> next = curr;
            one = one -> next;
        }
        else {
            two -> next = curr;
            two = two -> next;
        }

        curr = curr -> next;
    }

    // 0 and 1 ko jodo
    if(dummyOne -> next == NULL) zero -> next = dummyTwo -> next;
    else zero -> next = dummyOne -> next;

    // 1 and 2 ko jodo
    one -> next = dummyTwo -> next;
    
    // 2 ko null pr point karo
    two -> next = NULL;

    head = dummyZero -> next;

    return head;
}
