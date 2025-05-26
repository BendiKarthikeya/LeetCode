class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>x(n,vector<int>(m));
        vector<vector<int>>y(n,vector<int>(m));

        int mod = 12345;
        long long p = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                x[i][j]=p;
                p*=grid[i][j];
                p%=mod;
            }
        }
        p=1;
         for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                y[i][j]=p;
                p*=grid[i][j];
                p%=mod;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long answer = x[i][j] * y[i][j];
                ans[i][j]=answer%mod;
            }
        }
        return ans;
    }
};