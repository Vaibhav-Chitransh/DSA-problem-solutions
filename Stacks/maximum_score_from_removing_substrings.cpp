// Approach 1

class Solution {
public:
    int removeSub(string& s, string sub, int score) {
        int points = 0;
        stack<char> st;

        for(char ch : s) {
            if(!st.empty() && st.top() == sub[0] && ch == sub[1]) {
                points += score;
                st.pop();
            }
            else {
                st.push(ch);
            }
        }

        s.clear();
        while(!st.empty()) {
            s = st.top() + s;
            st.pop();
        }

        return points;
    }

    int maximumGain(string s, int x, int y) {
        int points = 0;

        if(x > y) {
            points += removeSub(s, "ab", x);
            points += removeSub(s, "ba", y);
        }
        else {
            points += removeSub(s, "ba", y);
            points += removeSub(s, "ab", x);
        }

        return points;
    }
};

// Approach 2

class Solution {
public:
    int removeSub(string& s, string sub, int score) {
        int  points = 0;
        int w = 0;

        for(int r=0; r<s.length(); r++) {
            s[w++] = s[r];

            if(w > 1 && s[w-2] == sub[0] && s[w-1] == sub[1]) {
                w = w - 2;
                points += score;
            }
        }

        s.erase(s.begin() + w, s.end());

        return points;
    }

    int maximumGain(string s, int x, int y) {
        int points = 0;

        if(x > y) {
            points += removeSub(s, "ab", x);
            points += removeSub(s, "ba", y);
        }
        else {
            points += removeSub(s, "ba", y);
            points += removeSub(s, "ab", x);
        }

        return points;
    }
};