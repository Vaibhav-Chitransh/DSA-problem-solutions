/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach 1

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        while(headA) {
            ListNode* curr = headB;

            while(curr) {
                if(curr == headA) return curr;
                curr = curr -> next;
            }

            headA = headA -> next;
        }

        return NULL;
    }
};

// Approach 2

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> mp;

        while(headA) {
            mp[headA] = true;
            headA = headA -> next;
        }

        while(headB) {
            if(mp[headB] == true) return headB;
            headB = headB -> next;
        }

        return NULL;
    }
};

// Approach 3

class Solution {
public:
    int getDiff(ListNode* headA, ListNode* headB) {
        int len1 = 0, len2 = 0;

        while(headA != NULL || headB != NULL) {
            if(headA) {
                len1++;
                headA = headA -> next;
            }

            if(headB) {
                len2++;
                headB = headB -> next;
            }
        }

        return len1 - len2;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int diff = getDiff(headA, headB);

        if(diff > 0) {
            while(diff--) {
                headA = headA -> next;
            }
        }
        else {
            while(diff++) {
                headB = headB -> next;
            }
        }

        while(headA) {
            if(headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }

        return NULL;
    }
};

// Approach 4

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        while(curr1 != curr2) {
            (curr1 == NULL) ? curr1 = headB : curr1 = curr1 -> next;
            (curr2 == NULL) ? curr2 = headA : curr2 = curr2 -> next;
        }

        return curr1;
    }
};