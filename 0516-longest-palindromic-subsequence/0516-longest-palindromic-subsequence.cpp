class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<char> arr1(s.begin(),s.end());
        vector<char> arr2(s.rbegin(),s.rend());
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return ans(n-1,n-1,arr1,arr2,dp);
    }
    int ans(int i,int j,vector<char>& arr1,vector<char>& arr2,vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]==-1){
            if(arr1[i]==arr2[j]){
                dp[i][j]=ans(i-1,j-1,arr1,arr2,dp)+1;
            }
            else{
                dp[i][j]=max(ans(i,j-1,arr1,arr2,dp),ans(i-1,j,arr1,arr2,dp));
            }
        }
        return dp[i][j];
    }
};