// Brute force approach 
class Solution {
public:
    bool finder(vector<vector<int>> matrix, int element) {
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == element) {
                    count++;
                }
            }
        }
        if(count == 2) {
            return false;
        }
        else {
            return true;
        }
    }

    bool findArray(vector<int> arr, int key) {
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == key) {
                return false;
            }
        }
        return true;
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        vector<int> store;

        int row = adjacentPairs.size();
        int col = 2;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(finder(adjacentPairs, adjacentPairs[i][j])) {
                    store.push_back(adjacentPairs[i][j]);
                }
            }
        }

        int start = store[0];
        ans.push_back(start);

        int k=0;
        while(k!=row) {
            for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(adjacentPairs[i][j] == start) {
                    if(j==1) {
                        if(findArray(ans, adjacentPairs[i][0])) {
                            ans.push_back(adjacentPairs[i][0]);
                            k++;
                            start = ans[k];
                        }
                    }
                    else {
                        if(findArray(ans, adjacentPairs[i][1])) {
                            ans.push_back(adjacentPairs[i][1]);
                            k++;
                            start = ans[k];
                        }
                    }
                }
            }
        }
        }

        return ans;
    }
};

// Optimal Solution 
class Solution {
public:
    void dfs(map<int,vector<int>>& m, set<int>& v, int a, vector<int>& ans) {
        if(v.find(a) != v.end()) {
            return ;
        }
        ans.push_back(a);
        v.insert(a);
        for(auto x:m[a]) {
            dfs(m, v, x, ans);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>> m;
        for(auto it:adjacentPairs) {
            m[it[0]].push_back(it[1]);
            m[it[1]].push_back(it[0]);
        }

        int head;
        for(auto it:m) {
            if(it.second.size() == 1) {
                head = it.first;
            }
        }

        set<int> v;
        vector<int> ans;
        dfs(m, v, head, ans);
        return ans;
    }
};