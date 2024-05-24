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
    void solve(ListNode* &head) {
        // Base case
        if(head == NULL || head -> next == NULL) {
            return ;
        }


        if(head -> val == head -> next -> val) {
            ListNode* nodeToDelete = head -> next;
            head -> next = nodeToDelete -> next;
            delete(nodeToDelete);
            solve(head);
        }

        else {
            solve(head -> next);
        }
    }

    ListNode* deleteDuplicates(ListNode* head) {
        // solve(head);

        if(head == NULL || head -> next == NULL) {
            return head;
        }

        ListNode* curr = head;

        while(curr -> next != NULL) {
            if(curr -> val == curr -> next -> val) {
                ListNode* nodeToDelete = curr -> next;
                curr -> next = nodeToDelete -> next;
                delete(nodeToDelete);
            }

            else {
                curr = curr -> next;
            }
        }

        return head;
    }
};