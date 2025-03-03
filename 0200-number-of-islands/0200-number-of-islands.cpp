class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;

    }
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
        int c[] = {-1, 1, 0, 0};
        int d[] = {0, 0, -1, 1};
        if(i<0|| j<0|| i>=n || j>=m||grid[i][j]=='0'){
            return;
        }   
        grid[i][j]='0';
        for(int l=0;l<4;l++){
            dfs(grid,i+c[l],j+d[l],n,m);
        }
    }

};