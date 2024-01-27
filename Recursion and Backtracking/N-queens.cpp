#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i, int j, vector<vector<char>>& board, int n) {
    // Checking for column
    int row = i;
    int col = j;
    while(row >=0 ) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row--;
    }

    // checking for top right 
    row = i;
    col = j;
    while(row >=0 && col <= n-1) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row--;
        col++;
    }

    // checking for top left 
    row = i;
    col = j;
    while(row >= 0 && col >= 0) {
        if(board[row][col] == 'Q') {
            return false;
        }
        row--;
        col--;
    }

    return true;
}

void solve(int i, int n, vector<vector<char>>& board, vector<int>& col,
vector<int>& topLeft, vector<int>& topRight) {
    // Base case
    if(i == n) {
        for(int x=0; x<n; x++) {
            for(int y=0; y<n; y++) {
                cout << board[x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return ;
    }

    // Recursive relation
    for(int j=0; j<n; j++) {
        // if(isSafe(i, j, board, n)) {
        //     board[i][j] = 'Q';
        //     solve(i+1, n, board);
        //     // Backtracking
        //     board[i][j] = '.';
        // }

        if(col[j] == 0 && topLeft[i - j + n - 1] == 0 && topRight[i + j] == 0) {
            board[i][j] = 'Q';
            col[j] = 1;
            topLeft[i-j+n-1] = 1;
            topRight[i+j] = 1;

            solve(i+1, n, board, col, topLeft, topRight);
            // BACktrACKING
            board[i][j] = '.';
            col[j] = topLeft[i-j+n-1] = topRight[i+j] = 0;
        }
    }
}

int main(){
    int n = 4;

    vector<vector<char>> board(n, vector<char> (n, '.'));

    vector<int> col(n, 0);
    vector<int> topLeft(2*n, 0);
    vector<int> topRight(2*n, 0);

    solve(0, n, board, col, topLeft, topRight);
    return 0;
}