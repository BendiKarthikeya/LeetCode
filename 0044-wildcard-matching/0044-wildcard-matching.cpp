class Solution {
public:
    bool isMatch(string s, string p) {
        vector<char> arr1(s.begin(),s.end());
        vector<char> arr2(p.begin(),p.end());
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        vector<int> pre(m,0);
        int sum=0;
        for(int i=0;i<m;i++){
            if(arr2[i]=='*'){
                sum=sum+1;
            }
            pre[i]=sum;
        }
        int answer=ans(n-1,m-1,arr1,arr2,dp,pre);
        return answer==1;

    }

    int ans(int i,int j,vector<char>& arr1,vector<char>& arr2,vector<vector<int>>& dp, vector<int>& pre){
        if(i<0 && j<0){
            return 1;
        }
        if(i<0){
            if(pre[j]==j+1){
                return 1;
            }
            else {
                return 0;
            }
        }
        if(j<0){
            return 0;
        }

        if(dp[i][j]==-1){
            if(arr1[i]==arr2[j] || arr2[j]=='?'){
                dp[i][j]= ans(i-1,j-1,arr1,arr2,dp,pre);
            }
            else if(arr2[j]=='*'){
                dp[i][j] =  ans(i,j-1,arr1,arr2,dp,pre) | ans(i-1,j,arr1,arr2,dp,pre);
            }
            else{
                dp[i][j]= 0;
            }
        }
        return dp[i][j];
        
    }
};