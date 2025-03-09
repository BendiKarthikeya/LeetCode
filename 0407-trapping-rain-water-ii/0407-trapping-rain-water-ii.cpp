class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n=heightMap.size();
        int m=heightMap[0].size();

        vector<vector<bool>> visted(n,vector<bool>(m,false));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0|| j==0|| i==n-1|| j==m-1){
                    pq.push({heightMap[i][j],i*m+j});
                    visted[i][j]=true;
                }
            }
        }
        int x[]={-1,1,0,0};
        int y[]={0,0,1,-1};

        while(!pq.empty()){
            pair<int, int> p = pq.top();

            pq.pop();
            int index=p.second;
            int i=index/m,j=index%m;
            for(int l=0;l<4;l++){
                int dx=i+x[l];
                int dy=j+y[l];
                if(dx>=0 && dx<n && dy>=0 && dy<m && visted[dx][dy]==false){
                    if(heightMap[i][j]> heightMap[dx][dy]){
                        ans+=heightMap[i][j]-heightMap[dx][dy];
                        heightMap[dx][dy]=heightMap[i][j];
                    }   
                    pq.push({heightMap[dx][dy],dx*m+dy});
                    visted[dx][dy]=true;
                }   
            }
        }
        return ans;
    }
};