// Approach 1

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string current = "";
        
        for (char ch : s) {
            if (ch == '(') {
                st.push(current);
                current = "";
            } else if (ch == ')') {
                reverse(current.begin(), current.end());
                current = st.top() + current;
                st.pop();
            } else {
                current += ch;
            }
        }
        
        return current;
    }
};

// Approach 2

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        vector<int> pairs(n);

        for(int i=0; i<n; i++) {
            if(s[i] == '(') st.push(i);
            if(s[i] == ')') {
                int j = st.top();
                st.pop();
                pairs[i] = j;
                pairs[j] = i;
            }
        }

        string ans = "";

        for(int i=0, dir=1; i<n; i+=dir) {
            if(s[i] == '(' || s[i] == ')') {
                i = pairs[i];
                dir = -dir;
            }
            else ans = ans + s[i];
        }

        return ans;
    }
};