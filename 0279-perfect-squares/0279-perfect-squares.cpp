class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return minAns(n, dp);
    }
    int minAns(int n, vector<int>& dp){
        if (n == 0) {
            return 0;
        }
        
        if (dp[n] == -1) {
            int mins = INT_MAX;
            for (int i = 1; i*i <= n; i++) {
                mins = min(mins, minAns((n - (i * i)), dp));
            }
            dp[n] = mins + 1;
        }
        
        return dp[n];
    }
};