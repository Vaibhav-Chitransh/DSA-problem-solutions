class Solution {
public:
    bool isValid(vector<vector<char>>& board, char digit, int row, int col) {
        for(int i=0; i<=8; i++) {
            // Checking the row
            if(board[row][i] == digit) {
                return false;
            }

            // Checking the col
            if(board[i][col] == digit) {
                return false;
            }
        }

        // Case for checking the sub boxes
        int startRow = row - (row%3);
        int startCol = col - (col%3);

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[startRow+i][startCol+j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        // Find the empty space present
        for(int i=0; i<=8; i++) {
            for(int j=0; j<=8; j++) {
                if(board[i][j] == '.') {
                    for(char digit='1'; digit<='9'; digit++) {
                        if(isValid(board, digit, i, j)) {
                            board[i][j] = digit;

                            // Recursive call 
                            if(solve(board) == true) {
                                return true;
                            }
                            else {
                                // Backtracting
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};