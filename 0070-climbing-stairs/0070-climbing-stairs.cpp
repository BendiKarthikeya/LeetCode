class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec(n+1,-1);
        return climb(n,vec);
    }
    int climb(int n,vector<int>& vec) {
        if(n<=1){
            return 1;
        }
        if(vec[n]==-1){
            vec[n]=climb(n-1,vec)+climb(n-2,vec);
        }
        return vec[n];
    }
};