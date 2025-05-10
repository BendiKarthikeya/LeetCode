class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> ans(n+1,true);
        ans[0]=false;
        ans[1]=false;
        for(int i=2;i<n+1;i++){
            if(ans[i]){
                for(int j=2;j*i<=n;j++){
                    ans[i*j]=false;
                }
            }
        }
        
        vector<vector<int>> result;
        for(int i=2;i<=n/2;i++){
            if(ans[i] && ans[n-i]){
                result.push_back({i,n-i});
            }
        }
        return result;
    }
};