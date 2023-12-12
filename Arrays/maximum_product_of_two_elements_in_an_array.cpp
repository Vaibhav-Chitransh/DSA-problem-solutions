class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        int a = nums[0] - 1;
        int b = nums[1] - 1;

        return a*b;
    }
};