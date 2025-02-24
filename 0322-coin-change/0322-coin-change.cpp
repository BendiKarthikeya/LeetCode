class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res= ans(n-1,amount,coins,dp);
        return res>=1e9 ? -1 : res;
    }
    int ans(int i,int j,vector<int>& coins,vector<vector<int>>& dp){
        if(j==0){
            return 0;
        }
        if(i<0 || j<0){
            return 1e9;
        }
        if(dp[i][j]==-1){
            int a=INT_MAX;
            if(j>=coins[i]){
                a=ans(i,j-coins[i],coins,dp)+1;
            }      
            int b=ans(i-1,j,coins,dp);
            dp[i][j]=min(a,b);
        }
        return dp[i][j];
    }
};