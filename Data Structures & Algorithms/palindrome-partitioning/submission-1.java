

class Solution {
    private List<List<String>> res = new ArrayList<>();
    private List<String> curr = new ArrayList<>();
    private boolean[][] dp;

    private void backtrack(String s, int start) {
        if (start >= s.length()) {
         res.add(new ArrayList<>(curr)); // Copy danh sách tạm vào kết quả
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (dp[start][i]) {
                curr.add(s.substring(start, i + 1)); // Java dùng substring(start, end)
                backtrack(s, i + 1);
                curr.remove(curr.size() - 1);    
            }
        }
    }

    public List<List<String>> partition(String s) {
        int n = s.length();
        dp = new boolean[n][n];

        // Vòng lặp DP kiểm tra Palindrome
        for (int r = 0; r < n; r++) {
            for (int l = 0; l <= r; l++) {
                if (s.charAt(l) == s.charAt(r) && (r - l <= 2 || dp[l + 1][r - 1])) {
                    dp[l][r] = true;
                }
            }
        }

        backtrack(s, 0);
        return res;
    }
}