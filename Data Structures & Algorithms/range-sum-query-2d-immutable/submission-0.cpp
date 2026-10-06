class NumMatrix {
private:
    vector<vector<int>> pref;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Mảng pref kích thước (m + 1) x (n + 1) để xử lý biên 0
        pref.assign(m + 1, vector<int>(n + 1, 0));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                pref[r + 1][c + 1] = matrix[r][c] 
                                  + pref[r][c + 1] 
                                  + pref[r + 1][c] 
                                  - pref[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Tối ưu O(1) nhờ công thức bù trừ
        return pref[row2 + 1][col2 + 1] 
             - pref[row1][col2 + 1] 
             - pref[row2 + 1][col1] 
             + pref[row1][col1];
    }
};