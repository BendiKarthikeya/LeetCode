class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return ans(n-1,nums,dp);
    }
    int ans(int i,vector<int>& nums,vector<int>& dp){
        if(i<0){
            return 0;
        }
        if(dp[i]==-1){
            dp[i]=max(ans(i-1,nums,dp),ans(i-2,nums,dp)+nums[i]);
        }
        return dp[i];
    }
};