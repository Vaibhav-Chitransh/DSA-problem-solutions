/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach 1 : Using map

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> vis;
        ListNode* temp = head;

        while(temp != NULL) {  // O(n)
            if(vis[temp] == true) {
                return true;
            }
            else {
                vis[temp] = true;
                temp = temp -> next;
            }
        }

        return false;
    }
};

// Approach 2 : Floyd Cycle Detection Algorithm

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;  // SC = O(1)
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};