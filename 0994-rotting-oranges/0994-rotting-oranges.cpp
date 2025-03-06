class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> time(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
            }
        }
        int e[]={-1,1,0,0};
        int f[]={0,0,1,-1};
        while(!que.empty()){
            pair pr = que.front();
            que.pop();
            for(int i=0;i<4;i++){
            int dx=pr.first+e[i];
            int dy=pr.second+f[i];
            if(dx>=0 && dx<n && dy>=0 && dy<m && grid[dx][dy]==1){
                que.push({dx,dy});
                time[dx][dy]=time[pr.first][pr.second]+1;
                grid[dx][dy]=2;
            }
        }
        }
            
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                t=max(t,time[i][j]);
            }
        }
        return t;
    }
};