class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1; // Số cách tới bậc (i - 2) [Lùi 2 bậc]
        int prev1 = 2; // Số cách tới bậc (i - 1) [Lùi 1 bậc]
        int curr = 0;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2; // f(i) = f(i-1) + f(i-2)

            prev2 = prev1; // Bậc (i-1) cũ trở thành bậc (i-2) cho vòng sau
            prev1 = curr;  // Bậc curr vừa tính trở thành bậc (i-1) cho vòng sau
        }

        return curr;
    }
};