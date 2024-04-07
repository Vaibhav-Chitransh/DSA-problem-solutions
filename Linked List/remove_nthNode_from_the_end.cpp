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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *curr = head;
        int len = 0;

        while (curr != NULL)
        {
            len++;
            curr = curr->next;
        }

        if (n == len)
        {
            ListNode *temp = head->next;
            head->next = NULL;
            delete (head);
            head = temp;
            return head;
        }

        int cnt = len - n - 1;

        curr = head;

        while (cnt)
        {
            curr = curr->next;
            cnt--;
        }

        ListNode *nodeToDelete = curr->next;
        curr->next = nodeToDelete->next;
        nodeToDelete->next = NULL;
        delete (nodeToDelete);

        return head;
    }
};

// Approach 2
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;

        while(n--) {
            fast = fast -> next;
        }

        if(fast == NULL) {
            ListNode* temp = head -> next;
            head -> next = NULL;
            delete(head);
            head = temp;
            return head;
        }

        ListNode* slow = head;

        while(fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next;
        }

        ListNode* nodeToDelete = slow -> next;
        slow -> next = nodeToDelete -> next;
        nodeToDelete -> next = NULL;
        delete(nodeToDelete);

        return head;
    }
};