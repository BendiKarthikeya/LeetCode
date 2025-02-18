class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<char> arr1(word1.begin(),word1.end());
        vector<char> arr2(word2.begin(),word2.end());
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return ans(n-1,m-1,arr1,arr2,dp);
    }
    int ans(int i,int j,vector<char>& arr1,vector<char>& arr2,vector<vector<int>>& dp){
        if(i<0 || j<0){
            return max(i+1,j+1);
        }
        if(dp[i][j]==-1){
            if(arr1[i]==arr2[j]){
                dp[i][j]=ans(i-1,j-1,arr1,arr2,dp);
            }
            else{
                dp[i][j]=min(ans(i,j-1,arr1,arr2,dp),min(ans(i-1,j-1,arr1,arr2,dp),ans(i-1,j,arr1,arr2,dp)))+1;
            }
        }
        return dp[i][j];
    }
};