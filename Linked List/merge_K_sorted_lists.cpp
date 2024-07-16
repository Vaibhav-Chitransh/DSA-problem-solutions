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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;

        for(int i=0; i<lists.size(); i++) {
            ListNode* curr = lists[i];

            while(curr) {
                v.push_back(curr -> val);
                curr = curr -> next;
            }
        }

        sort(v.begin(), v.end());

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        for(int i=0; i<v.size(); i++) {
            ListNode* newNode = new ListNode(v[i]);
            temp -> next = newNode;
            temp = temp -> next;
        }

        return dummyNode -> next;
    }
};

// Approach 2

class Solution {
public:
    ListNode* merge(ListNode* &head1, ListNode* &head2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        while(head1 != NULL && head2 != NULL) {
            if(head1 -> val < head2 -> val) {
                curr -> next = head1;
                head1 = head1 -> next;
            }
            else {
                curr -> next = head2;
                head2 = head2 -> next;
            }
            curr = curr -> next;
        }

        if(head1) curr -> next = head1;
        if(head2) curr -> next = head2;

        return dummyNode -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* head = lists[0];

        for(int i=1; i<lists.size(); i++) {
            head = merge(head, lists[i]);
        }

        return head;
    }
};

// Approach 3

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i=0; i<lists.size(); i++) {
            if(lists[i] != NULL) pq.push({lists[i] -> val, lists[i]});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(!pq.empty()) {
            auto mini = pq.top();
            pq.pop();

            curr -> next = mini.second;
            curr = curr -> next;

            if(mini.second -> next) {
                pq.push({mini.second -> next -> val, mini.second -> next});
            }
        }

        return dummy -> next;
    }
};