class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int j=0;
            int k=i-1;
            int sum=0;
            while(k>=0){
                sum+=dp[j]*dp[k];
                j++;
                k--;
            }
            dp[i]=sum;
        }
        return dp[n];
    }
};