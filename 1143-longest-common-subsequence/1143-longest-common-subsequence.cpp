class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<char> charVector1(text1.begin(), text1.end());
        vector<char> charVector2(text2.begin(), text2.end());
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return ans(charVector1,charVector2,n-1,m-1,dp);
    }
    int ans(vector<char>& charVector1, vector<char>& charVector2,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]==-1){
            if(charVector1[i]==charVector2[j]){
                dp[i][j]= ans(charVector1,charVector2,i-1,j-1,dp)+1;
            }
            else
            {
                dp[i][j]= max(ans(charVector1,charVector2,i,j-1,dp),ans(charVector1,charVector2,i-1,j,dp));
            }
        }
        return dp[i][j];
    }
};