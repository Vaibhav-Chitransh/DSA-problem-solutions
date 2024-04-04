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
class Solution {
public:
    void reverse(ListNode*& head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = NULL;

        while(curr != NULL) {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
    }
    ListNode* removeNodes(ListNode* head) {

        if(head -> next == NULL) {
            return head;
        }

        reverse(head);

        ListNode* curr = head;
        int maxi = head -> val;
        ListNode* temp = NULL;

        while(curr != NULL && curr -> next != NULL) {
            temp = curr -> next;

            if(temp -> val < maxi) {
                curr -> next = temp -> next;
                temp -> next = NULL;
                delete(temp);
            }

            else {
                maxi = temp -> val;
                curr = curr -> next;
            }
        }

        reverse(head);

        return head;
    }
};