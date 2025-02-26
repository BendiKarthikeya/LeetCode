class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        int sum = 0;
        for (int num : arr) sum += num;

        if (target > sum || target < -sum) return 0;

        vector<vector<int>> dp(n, vector<int>(2*sum + 1, -1));
        return ans(n - 1, 0,target, arr, dp,sum);
    }
    int ans(int i, int j,int target ,vector<int>& arr, vector<vector<int>>& dp,int sum) {
        if (i < 0) return j==target?1:0;
        if (dp[i][j+sum] == -1){
            int exclude = ans(i - 1, j + arr[i],target,arr, dp,sum); 
            int include = ans(i - 1, j -arr[i],target,arr, dp,sum);             
            dp[i][j+sum] = include + exclude; 
        } 
        return dp[i][j+sum]; 
    }
};