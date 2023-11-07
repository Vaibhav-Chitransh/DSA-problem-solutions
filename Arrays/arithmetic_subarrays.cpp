bool checkArithmeticSequence(vector<int>& v) {
    int value = v[1] - v[0];
    int n = v.size();

    for(int i=1; i<n-1; i++) {
        if(value != v[i+1] - v[i]) {
            return false;
        }
    }
    return true;
}

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    int array_size = nums.size();
    int left_size = l.size();
    // right size will be same as left size
    vector<bool> ans;

    int i = 0;
    while(i < left_size) {
        int a = l[i];
        int b = r[i];

        vector<int> v(nums.begin() + a, nums.begin() + b + 1);

        sort(v.begin(), v.end());
        bool temp = checkArithmeticSequence(v);
        ans.push_back(temp);
        i++;
    }
    return ans;
}