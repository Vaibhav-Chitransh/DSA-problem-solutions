class Solution {
public:
    void find_subsets(vector<int>& nums, vector<int> subs, int index, vector<vector<int>>& ans) {
        // base case
        if(index >= nums.size()) {
            ans.push_back(subs);
            return ;
        }

        // recursive call for excluding the elements
        find_subsets(nums, subs, index+1, ans);

        // recursive call for including the elements
        int element = nums[index];
        subs.push_back(element);
        find_subsets(nums, subs, index+1, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        int index = 0;

        find_subsets(nums, sub, index, ans);

        return ans;
    }
};