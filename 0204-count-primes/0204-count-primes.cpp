class Solution {
public:
    int countPrimes(int n) {
        vector<bool> ans(n+1,true);
        ans[0]=false;
        ans[1]=false;
        for(int i=2;i<=n;i++){
            if(ans[i]==true){
                for(int j=2;i*j<=n;j++){
                    ans[i*j]=false;
                }
            }
        }
        int count=0;
        for(int i=0;i<n+1;i++){
            if(ans[i]==true){
                count++;
            }
        }
        return count;
    }
};