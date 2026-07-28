class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] == '.')
                    continue;
                
                int box = (i/3)*3 + (j/3);

                if (rows[i].count(board[i][j]))
                    return false;
                
                if (cols[j].count(board[i][j]))
                    return false;
                
                if (boxes[box].count(board[i][j]))
                    return false;
                
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                boxes[box].insert(board[i][j]);
            }
        }
        return true;
    }
};
