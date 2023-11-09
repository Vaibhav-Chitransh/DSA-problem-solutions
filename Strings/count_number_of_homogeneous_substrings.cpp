class Solution {
public:
    int countHomogenous(string s) {
        int m = 1e9 + 7;

        if(s.size() == 0) {
            return 0;
        }

        vector<int> len(s.size(), 0);
        len[0] = 1;
        int sum = 1;

        for(int i=1; i<s.size(); i++) {
            len[i] = 1;
            if(s[i] == s[i-1]) {
                len[i] = (len[i]%m + len[i-1]%m)%m;
            }
            sum = (sum%m + len[i]%m)%m;
        }
        return sum;
    }
};