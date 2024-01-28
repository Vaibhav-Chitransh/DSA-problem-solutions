#include<iostream>
#include<vector>
using namespace std;

void findCombinations(int index, int target, int sum, vector<int>& comb, 
vector<vector<int>>& ans, vector<int>& v) {
    // Base case
    if(index >= v.size()) {
        return ;
    }

    if(sum == target) {
        ans.push_back(comb);
        return ;
    }

    // Recursive relation

    // Pick element
    if(sum + v[index] <= target) {
        comb.push_back(v[index]);
        findCombinations(index, target, sum + v[index], comb, ans, v);

        // BackTracking
        comb.pop_back();
    }

    // Not picking
    findCombinations(index+1, target, sum, comb, ans, v);
}

int main(){
    vector<int> v {2,3,4};
    int target = 6;

    vector<int> comb;
    vector<vector<int>> ans;

    int index = 0;
    int sum = 0;

    findCombinations(index, target, sum, comb, ans, v);

    for(int i=0; i<ans.size(); i++) {
        for(auto j:ans[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}