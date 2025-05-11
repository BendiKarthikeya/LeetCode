class Solution {
public:
    vector<int> closestPrimes(int l, int r) {
        vector<bool> ans(r+1,true);
        ans[0]=ans[1]=false;
        for(int i=2;i*i<=r;i++){
            if(ans[i]){
                for(int j=i*i;j<=r;j+=i){
                    ans[j]=false;
                }
            }
            
        }
       int prev = -1;
        int minDiff = INT_MAX;
        vector<int> res = {-1, -1};
        for(int i=l;i<=r;i++){
            if (ans[i]) {
                if(prev!=-1 && i-prev < minDiff){
                    minDiff=i-prev;
                    res={prev,i};
                } 
                prev=i;
            }
            
        }
        
        return res;
    }
};