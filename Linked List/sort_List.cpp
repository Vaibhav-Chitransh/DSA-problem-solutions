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
    ListNode* getMiddle(ListNode* &head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }

    ListNode* mergeList(ListNode* &left, ListNode* &right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(left != NULL && right != NULL) {
            if(left -> val < right -> val) {
                temp -> next = left;
                left = left -> next;
            }
            else {
                temp -> next = right;
                right = right -> next;
            }
            temp = temp -> next;
        }

        if(left != NULL) temp -> next = left;
        if(right != NULL) temp -> next = right;

        return dummyNode -> next;
    }

    ListNode* mergeSort(ListNode* &head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* midNode = getMiddle(head);
        ListNode* left = head;
        ListNode* right = midNode -> next;
        midNode -> next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);

        ListNode* newHead = mergeList(left, right);
        return newHead;
    }

    ListNode* sortList(ListNode* head) {
        ListNode* ans = mergeSort(head);
        return ans;
    }
};