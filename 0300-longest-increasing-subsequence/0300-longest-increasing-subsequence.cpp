class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            int ans=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    ans=max(ans,dp[j]);
                }
            }
            dp[i]=ans+1;
        }
        int ans=1;
        for(int i=0;i<dp.size();i++){
            ans=max(ans,dp[i]);
        }
        return  ans;

    }
};