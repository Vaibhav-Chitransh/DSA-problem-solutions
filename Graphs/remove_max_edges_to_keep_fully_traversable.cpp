class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int x) {
        if (parent[x] != x) {
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = findParent(x);
        int rootY = findParent(y);

        if (rootX == rootY) return false;

        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU dsuAlice(n), dsuBob(n);
        int totalEdges = edges.size();
        int usedEdges = 0;

        for (auto& edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 3) {
                if (dsuAlice.unite(u, v) | dsuBob.unite(u, v)) {
                    usedEdges++;
                }
            }
        }

        for (auto& edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (type == 1) {
                if (dsuAlice.unite(u, v)) {
                    usedEdges++;
                }
            } else if (type == 2) {
                if (dsuBob.unite(u, v)) {
                    usedEdges++;
                }
            }
        }

        int aliceComponents = 0, bobComponents = 0;
        for (int i = 1; i <= n; i++) {
            if (dsuAlice.findParent(i) == i) {
                aliceComponents++;
            }
            if (dsuBob.findParent(i) == i) {
                bobComponents++;
            }
        }

        if (aliceComponents != 1 || bobComponents != 1) {
            return -1;
        }

        return totalEdges - usedEdges;
    }
};
