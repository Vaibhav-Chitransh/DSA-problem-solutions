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

// Appraoch 1

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head -> next;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int sum = 0;

        while(curr) {

            if(curr -> val != 0) sum += curr -> val;

            else {
                ListNode* newNode = new ListNode(sum);
                temp -> next = newNode;
                temp = temp -> next;
                sum = 0;
            }
            
            curr = curr -> next;
        }

        return dummy -> next;
    }
};

// Approach 2

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head -> next;
        ListNode* temp = head -> next;
        int sum = 0;

        while(curr) {
            if(temp -> val != 0) {
                sum += temp -> val;
                temp = temp -> next;
            }
            else {
                curr -> val = sum;
                sum = 0;
                curr -> next = temp -> next;
                curr = curr -> next;
                temp = curr;
            }
        }

        return head -> next;
    }
};