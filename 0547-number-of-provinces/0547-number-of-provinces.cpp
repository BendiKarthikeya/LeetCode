class Solution {
public:
    void dfs(int u,unordered_map<int,vector<int>>& um,vector<bool>& vis){
        vis[u]=true;
        for (int v : um[u]) {
            if (!vis[v]) {
                dfs(v, um, vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>> um;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                        um[i].push_back(j);    
                }
            }
        }
        vector<bool> vis(n,false);
        int count=0;
        
        
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                dfs(i,um,vis);
                count++;
            }
        }
        return count;
    }
};