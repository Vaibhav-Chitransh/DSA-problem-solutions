/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Approach 1

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* oldNode = head;

        while(oldNode) {
            Node* newNode = new Node(oldNode -> val);
            mp[oldNode] = newNode;
            oldNode = oldNode -> next;
        }

        oldNode = head;

        while(oldNode) {
            Node* newNode = mp[oldNode];
            newNode -> next = mp[oldNode -> next];
            newNode -> random = mp[oldNode -> random];
            oldNode = oldNode -> next;
        }

        return mp[head];
    }
};

// Approach 2

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Insert the nodes in between
        Node* curr = head;

        while(curr) {
            Node* newNode = new Node(curr -> val);
            newNode -> next = curr -> next;
            curr -> next = newNode;
            curr = curr -> next -> next;
        }

        // Arrange the random pointers
        curr = head;

        while(curr) {
            Node* newNode = curr -> next;
            if(curr -> random == NULL) newNode -> random = NULL;
            else newNode -> random = curr -> random -> next;
            curr = curr -> next -> next;
        }

        // next pointers and alag alag
        curr = head;
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while(curr) {
            temp -> next = curr -> next;
            temp = temp -> next;

            curr -> next = curr -> next -> next;
            curr = curr -> next;
        }

        return dummyNode -> next;
    }
};