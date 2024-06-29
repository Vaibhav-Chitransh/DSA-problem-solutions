// Approach 1

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for(auto it:adj[node]) {
            if(!vis[it]) dfs(it, adj, vis);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);
        }

        vector<vector<int>> ans(n);

        for(int i=0; i<n; i++) {
            vector<int> vis(n, 0);
            vector<int> arr;

            dfs(i, adj, vis);

            for(int j=0; j<n; j++) {
                if(vis[j] && i != j) arr.push_back(j);
            }

            ans[i] = arr;
        }

        return ans;
    }
};

// Approach 2

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (int i=0; i<edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            adj[from].push_back(to);
            indegree[to]++;
        }

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);

            for (int neighbour : adj[curr]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        vector<vector<int>> ancestorsList(n);
        vector<set<int>> ancestorsSetList(n);

        for (int node : topo) {
            for (int neighbour : adj[node]) {
                ancestorsSetList[neighbour].insert(node);
                ancestorsSetList[neighbour].insert(
                    ancestorsSetList[node].begin(),
                    ancestorsSetList[node].end());
            }
        }

        for (int i = 0; i < ancestorsList.size(); i++) {
            ancestorsList[i].assign(ancestorsSetList[i].begin(),ancestorsSetList[i].end());
            sort(ancestorsList[i].begin(), ancestorsList[i].end());
        }

        return ancestorsList;
    }
};