class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n-1, -1);
        int result1 = ans(n-2, dp1, nums, 0, n-2);
        vector<int> dp2(n-1, -1);
        int result2 = ans(n-1, dp2, nums, 1, n-1);
        
        return max(result1, result2);
    }
    
    int ans(int i, vector<int>& dp, vector<int>& nums, int start, int end) {
        if (i < start) {
            return 0;
        }
        
        int idx = i - start; 
        
        if (dp[idx] == -1) {
            dp[idx] = max(ans(i-1, dp, nums, start, end), 
                          ans(i-2, dp, nums, start, end) + nums[i]);
        }
        
        return dp[idx];
    }
};