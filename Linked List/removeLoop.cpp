/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

void removeCycle(Node* &head, Node* &slow, Node* &fast) {
    slow = head;

    if(slow == fast) {
        while(fast -> next != slow) {
            fast = fast -> next;
        }
        fast -> next = NULL;
        return ;
    }

    while(slow -> next != fast -> next) {
        slow = slow -> next;
        fast = fast -> next;
    }

    fast -> next = NULL;
}

Node *removeLoop(Node *head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) {
            removeCycle(head, slow, fast);
            return head;
        }
    }

    return head;
}