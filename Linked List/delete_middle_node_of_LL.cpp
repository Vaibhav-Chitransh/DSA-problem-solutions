/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Approach 1

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return NULL;
        }

        ListNode* curr = head;
        int len = 0;

        while(curr != NULL) {
            curr = curr -> next;
            len++;
        }

        int mid = len/2;
        curr = head;

        while(mid > 1) {
            curr = curr -> next;
            mid--;
        }

        ListNode* nodeToDelete = curr -> next;
        curr -> next = nodeToDelete -> next;
        nodeToDelete -> next = NULL;
        delete(nodeToDelete);

        return head;
    }
};

// Approach 2

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast -> next != NULL) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = slow -> next;
        slow -> next = NULL;
        delete(slow);

        return head;
    }
};