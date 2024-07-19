// Approach 1

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> res;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {

                int currRow = i;
                int currCol = j;

                int rowMin = INT_MAX;
                int colMax = INT_MIN;

                for(int k=0; k<cols; k++) rowMin = min(rowMin, matrix[currRow][k]);
                for(int k=0; k<rows; k++) colMax = max(colMax, matrix[k][currCol]);

                if(matrix[currRow][currCol] == rowMin && matrix[currRow][currCol] == colMax) {
                    res.push_back(matrix[currRow][currCol]);
                }
            }
        }

        return res;
    }
};

// Approach 2

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> res;
        vector<int> rowMin(rows, INT_MAX), colMax(cols, INT_MIN);

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    res.push_back(matrix[i][j]);
                }
            }
        }

        return res;
    }
};

// Approach 3

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> res;
        
        for(int i=0; i<rows; i++) {
            int currRow = i, rowMin = INT_MAX, rowMinCol = -1;
            for(int j=0; j<cols; j++) {
                if(matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                    rowMinCol = j;
                }
            }

            int currCol = rowMinCol, colMax = INT_MIN, colMaxRow = -1;
            for(int k=0; k<rows; k++) {
                if(matrix[k][currCol] > colMax) {
                    colMax = matrix[k][currCol];
                    colMaxRow = k;
                }
            }

            if(currRow == colMaxRow) res.push_back(matrix[currRow][currCol]);
        }

        return res;
    }
};

// Approach 4

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> res;
        
        for(int i=0; i<rows; i++) {
            int currRow = i, rowMin = INT_MAX, rowMinCol = -1;
            for(int j=0; j<cols; j++) {
                if(matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                    rowMinCol = j;
                }
            }
            int currCol = rowMinCol, colMax = INT_MIN, colMaxRow = -1;
            for(int k=0; k<rows; k++) {
                if(matrix[k][currCol] > colMax) {
                    colMax = matrix[k][currCol];
                    colMaxRow = k;
                }
            }

            if(currRow == colMaxRow) {
                res.push_back(matrix[currRow][currCol]);
                return res;
            }
        }

        return res;
    }
};