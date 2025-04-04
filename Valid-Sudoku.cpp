class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return ans(board, 0, 0);
    }
    
    bool ans(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return ans(board, row + 1, 0);
        if (board[row][col] == '.') return ans(board, row, col + 1);
        
        if (!SAFE(board, row, col)) return false;
        return ans(board, row, col + 1);
    }

    bool SAFE(vector<vector<char>>& board, int row, int col) {
        char c = board[row][col];
        // Row check
        for (int j = 0; j < 9; j++) {
            if (board[j][col] == c && j != row) return false;
        }
        // Column check
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c && i != col) return false;
        }
        // 3x3 box check
        int boxRow = 3 * (row / 3);
        int boxCol = 3 * (col / 3);
        for (int i = boxRow; i < boxRow + 3; i++) {
            for (int j = boxCol; j < boxCol + 3; j++) {
                if (board[i][j] == c && (i != row || j != col)) return false;
            }
        }
        return true;
    }
};
