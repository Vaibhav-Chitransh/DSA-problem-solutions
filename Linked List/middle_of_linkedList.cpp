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
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int len = 0;

        while(curr != NULL) {
            curr = curr -> next;
            len++;
        }

        int mid = len/2;
        curr = head;

        while(mid != 0) {
            curr = curr -> next;
            mid--;
        }

        return curr;
    }
};

// Approach 2

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }
};