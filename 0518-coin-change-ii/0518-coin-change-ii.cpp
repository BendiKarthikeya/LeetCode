class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return ans(n-1,amount,coins,dp);
    }
    int ans(int i,int j,vector<int>& coins,vector<vector<int>>& dp){
        if(j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]==-1){
            int a= 0;
            if(j>=coins[i]){
                a=ans(i,j-coins[i],coins,dp);
            }
            int b=ans(i-1,j,coins,dp);
            dp[i][j]=a+b;
        }
        return dp[i][j];
    }
};