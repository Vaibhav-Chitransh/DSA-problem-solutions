#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});    // {{0, 1}, {0, 4}, {1, 2}, ....}
    }

    vector<vector<int>> adjMat(n, vector<int>(n, 0));

    for(auto it : edges) {
        int u = it[0], v = it[1];

        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << adjMat[i][j] << " ";
        } cout << endl;
    } cout << endl;

    vector<vector<int>> adjList(n);

    for(auto it : edges) {
        int u = it[0], v = it[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=0; i<n; i++) {
        cout << i << " -> ";
        for(int j=0; j<adjList[i].size(); j++) {
            cout << adjList[i][j] << " ";
        } cout << endl;
    } cout << endl;

    return 0;
}