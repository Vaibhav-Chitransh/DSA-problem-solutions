#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void letterCombinations(string digits, unordered_map<char, string>& mp, vector<string>& ans, string& combinations,
int index) {
    // Base case
    if(index >= digits.size()) {
        ans.push_back(combinations);
        return ;
    }

    string str = mp[digits[index]];

    for(int i=0; i<str.size(); i++) {
        combinations.push_back(str[i]);
        // recursive call
        letterCombinations(digits, mp, ans, combinations, index+1);
        // Backtracking
        combinations.pop_back();
    }
}

int main(){
    string digits = "356";
    vector<string> ans;
    string combinations;

    // For keeping track of the strings corresponding to the number
    unordered_map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    int index = 0;

    letterCombinations(digits, mp, ans, combinations, index);

    for(int i=0; i<ans.size(); i++) {
        for(auto j:ans[i]) {
            cout << j;
        }
        cout <<", ";
    }cout << endl;
    return 0;
}