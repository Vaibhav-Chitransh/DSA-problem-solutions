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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans(2, -1);

        ListNode* prev = head;
        ListNode* curr = head -> next;

        int currIndex = 1;
        int prevCriticalIndex = 0;
        int firstCriticalIndex = 0;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        while(curr -> next != NULL) {
            if((curr -> val > prev -> val && curr -> val > curr -> next -> val) || 
                (curr -> val < prev -> val && curr -> val < curr -> next -> val)) {

                    if(prevCriticalIndex == 0) {
                        prevCriticalIndex = currIndex;
                        firstCriticalIndex = currIndex;
                    }

                    else {
                        mini = min(mini, currIndex - prevCriticalIndex);
                        prevCriticalIndex = currIndex;
                    }
            }

            currIndex++;
            prev = curr;
            curr = curr -> next;
        }

        if(mini != INT_MAX) {
            maxi = prevCriticalIndex - firstCriticalIndex;
            ans = {mini, maxi};
        }

        return ans;

    }
};