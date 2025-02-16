class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
            int target=sum/2;
            vector<vector<int>> dp(n,vector<int>(target+1,-1));
            int answer=ans(n-1,arr,target,dp);
            return answer == 1 ? true : false;
        }

    }
    int ans(int i,vector<int>& arr,int k,vector<vector<int>>& dp){
        if(i<0){
            return k==0 ? 1 : 0;
        }
        if(dp[i][k]==-1){
            int c1=ans(i-1,arr,k,dp);
            int c2=0;
            if(k>=arr[i]){
                c2=ans(i-1,arr,k-arr[i],dp);
            }
            dp[i][k]=c1|c2;
        }
        return dp[i][k];
    }
};