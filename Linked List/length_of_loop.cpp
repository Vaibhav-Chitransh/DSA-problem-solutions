/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
int findingLength(Node*& slow, Node*&fast, Node*&head) {
    int count = 1;
    
    while(slow -> next != fast) {
        slow = slow -> next;
        count++;
    }
    
    return count;
}

int countNodesinLoop(struct Node *head)
{
    // Detecting loop
    Node* slow = head;
    Node*fast = head;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        
        if(slow == fast) {
            int len = findingLength(slow, fast, head);
            return len;
        }
    }
    
    return 0;
}