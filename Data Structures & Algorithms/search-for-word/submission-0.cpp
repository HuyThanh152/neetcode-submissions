class Solution {
public:
int m, n;
bool backtrack(vector<vector<char>> & board, string word, int row, int col, int idx){
    if (idx == word.length()) return true;
    if(row >= m || col >= n|| row < 0 || col < 0|| word[idx] != board[row][col]) return false;
    char tmp = board[row][col];
    board [row][col] ='#';
    bool found = backtrack(board, word, row+1, col, idx+1) ||
    backtrack(board, word, row-1, col, idx+1)||
    backtrack(board, word, row, col+1, idx+1) ||
    backtrack(board, word, row, col-1, idx+1);
    board[row][col] = tmp;
    return found;    
}

    bool exist(vector<vector<char>>& board, string word) {
         m = board.size();
         n = board[0].size();
        for (int i = 0; i < m; i++)
           for (int j = 0; j < n; j++){
            if( backtrack(board, word, i, j, 0) )
               return true;
           }
        return false;
    }
};
