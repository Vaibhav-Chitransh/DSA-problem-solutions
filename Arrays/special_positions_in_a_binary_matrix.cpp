class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int result = 0;

        for(int i=0; i<row; i++) {
            int count = 0;
            int m = 0;
            for(int j=0; j<col; j++) {
                if(mat[i][j] == 1) {
                    count++;
                    m = j;
                }
            }
            if(count == 1) {
                int cnt = 0;
                for(int k=0; k<row; k++) {
                    if(mat[k][m] == 1) {
                        cnt++;
                    } 
                }
                if(cnt == 1) {
                    result++;
                }
            }
        }
        return result;
    }
};