class Solution {
public:
    string sortVowels(string s) {
        vector<char> store;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                store.push_back(s[i]);
            }
        }

        sort(store.begin(), store.end());
        int j = 0;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                s[i] = store[j];
                j++;
            }
        }
        return s;
    }
};