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
    ListNode* findMiddle(ListNode* &head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    void reverse(ListNode* &head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while(curr) {
            nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    void reorderList(ListNode* head) {
        // Find the middle
        ListNode* middle = findMiddle(head);

        // Partition into two halves
        ListNode* head2 = middle -> next;
        middle -> next = NULL;

        // Reverse the second half
        reverse(head2);

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(head != NULL || head2 != NULL) {
            if(head) {
                temp -> next = head;
                head = head -> next;
                temp = temp -> next;
            }
            if(head2) {
                temp -> next = head2;
                head2 = head2 -> next;
                temp = temp -> next;
            }
        }

        head = dummyNode -> next;
    }
};