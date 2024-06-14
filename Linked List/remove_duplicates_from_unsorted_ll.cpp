#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    unordered_map<int, bool> m;

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL) {
        if(m[curr -> data] == true) {
            // Deletion
            prev -> next = curr -> next;
            curr -> next = NULL;
            delete(curr);
            curr = prev -> next;
        }
        else {
            m[curr -> data] = true;
            prev = curr;
            curr = curr -> next;
        }
    }

    return head;
}