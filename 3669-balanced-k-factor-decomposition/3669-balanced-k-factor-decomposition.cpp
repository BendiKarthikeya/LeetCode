class Solution {
public:
    vector<int> ans;
    int bestDiff = INT_MAX;

    vector<int> minDifference(int n, int k) {
        vector<int> curr;
        backtracking(n,k,1,curr);
        return ans;
    }
    void backtracking(int n,int k,int start,vector<int>& curr){
        if(k==1){
            if(n>=start){
                curr.push_back(n);
                check(curr);
                curr.pop_back();
            }
            return;
        }
        for(int i=start;i<=n;i++){
            if(n%i==0){
                curr.push_back(i);
                backtracking(n/i,k-1,i,curr);
                curr.pop_back();
            }
        }
    }
    void check(vector<int>& curr){
        int mn=*min_element(curr.begin(),curr.end());
        int mx=*max_element(curr.begin(),curr.end());
        if(mx-mn < bestDiff){
            bestDiff = mx-mn;
            ans=curr;
        }
    }
};