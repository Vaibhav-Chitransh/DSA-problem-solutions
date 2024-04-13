/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findStartNode(ListNode* &head, ListNode* &slow, ListNode* &fast) {
        slow = head;

        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                ListNode* startNode = findStartNode(head, slow, fast);
                return startNode;
            }
        }

        return NULL;
    }
};