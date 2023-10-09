/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node* insertingNode = new Node(data);
        Node* temp = NULL;
        Node* curr = head;
        
        if(data <= head -> data) {
            insertingNode -> next = curr;
            head = insertingNode;
        }
        
        else {
            while(curr -> data <= data && curr -> next != NULL) {
                temp = curr;
                curr = curr -> next;
            }
            
            if(curr -> next == NULL && curr -> data < data) {
                curr -> next = insertingNode;
                insertingNode -> next = NULL;
            }
            
            else {
                insertingNode -> next = curr;
                temp -> next = insertingNode;
            }
        }
        
        return head;
    }
};