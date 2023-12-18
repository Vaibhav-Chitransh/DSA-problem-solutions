class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0];
        int b = nums[1];

        int size = nums.size();

        int c = nums[size-1];
        int d = nums[size-2];

        return (c*d)-(a*b);
    }
};