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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> v;
        ListNode* curr = list1;

        while(curr != NULL) {
            v.push_back(curr -> val);
            curr = curr -> next;
        }

        curr = list2;

        while(curr != NULL) {
            v.push_back(curr -> val);
            curr = curr -> next;
        }

        sort(v.begin(), v.end());

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        for(int i=0; i<v.size(); i++) {
            temp -> next = new ListNode(v[i]);
            temp = temp -> next;
        }

        return dummyNode -> next;
    }
};

// Approach 2

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> v;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 != NULL && curr2 != NULL) {
            if(curr1 -> val <= curr2 -> val) {
                v.push_back(curr1 -> val);
                curr1 = curr1 -> next;
            }

            else {
                v.push_back(curr2 -> val);
                curr2 = curr2 -> next;
            }
        }

        while(curr2 != NULL) {
            v.push_back(curr2 -> val);
            curr2 = curr2 -> next;
        }

        while(curr1 != NULL) {
            v.push_back(curr1 -> val);
            curr1 = curr1 -> next;
        }

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        for(int i=0; i<v.size(); i++) {   // O(n)
            temp -> next = new ListNode(v[i]);
            temp = temp -> next;
        }

        return dummyNode -> next;
    }
};

// Approach 3

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 != NULL && list2 != NULL) {
            if(list1 -> val < list2 -> val) {
                temp -> next = list1;
                list1 = list1 -> next;
            }

            else {
                temp -> next = list2;
                list2 = list2 -> next;
            }

            temp = temp -> next;
        }

        if(list2 != NULL) {
            temp -> next = list2;
        }

        if(list1 != NULL) {
            temp -> next = list1;
        }

        return dummyNode -> next;
    }
};