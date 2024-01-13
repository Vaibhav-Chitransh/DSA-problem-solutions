class Solution{
    public:
    void findPath(vector<vector<int>>& m, int n, string path, vector<vector<int>>& vis,
        vector<string>& ans, int x, int y) {
            // Base case
            if(x == n-1 && y == n-1) {
                ans.push_back(path);
                return ;
            }
            
            vis[x][y] = 1;
            
            // 4 choices - down, left, right, up
            
            // if I move downwards
            int coord_x = x+1;
            int coord_y = y;
            
            if(isSafe(m, n, coord_x, coord_y, vis)) {
                path.push_back('D');
                findPath(m, n, path, vis, ans, coord_x, coord_y);
                // backtracking
                path.pop_back();
            }
            
            // if I move left
            coord_x = x;
            coord_y = y-1;
            
            if(isSafe(m, n, coord_x, coord_y, vis)) {
                path.push_back('L');
                findPath(m, n, path, vis, ans, coord_x, coord_y);
                path.pop_back();
            }
            
            // if I move right
            coord_x = x;
            coord_y = y+1;
            
            if(isSafe(m, n, coord_x, coord_y, vis)) {
                path.push_back('R');
                findPath(m, n, path, vis, ans, coord_x, coord_y);
                path.pop_back();
            }
            
            // if I move up
            coord_x = x-1;
            coord_y = y;
            
            if(isSafe(m, n, coord_x, coord_y, vis)) {
                path.push_back('U');
                findPath(m, n, path, vis, ans, coord_x, coord_y);
                path.pop_back();
            }
            
            vis[x][y] = 0;
        }
        
    bool isSafe(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> vis) {
        if((x >=0 && x < n && y >=0 && y < n) && (vis[x][y] == 0) && (m[x][y] == 1)) {
            return true;
        }
        return false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m[0][0] == 0) {
            return ans;
        }
        
        vector<vector<int>> vis = m;
        
        // Initialize with 0
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                vis[i][j] = 0;
            }
        }
        
        int x = 0;
        int y = 0;
        
        string path = "";
        findPath(m, n, path, vis, ans, x, y);
        sort(ans.begin(), ans.end());
        return ans;
    }
};