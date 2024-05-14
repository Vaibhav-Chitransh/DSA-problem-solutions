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
    ListNode* getMiddleNode(ListNode* &head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* &head) {
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
        return head;
    }

    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL) {
            return true;
        }

        ListNode* midNode = getMiddleNode(head);
        ListNode* head2 = reverse(midNode -> next);

        while(head2 != NULL) {
            if(head -> val != head2 -> val) {
                return false;
            }

            head = head -> next;
            head2 = head2 -> next;
        }

        return true;
    }
};