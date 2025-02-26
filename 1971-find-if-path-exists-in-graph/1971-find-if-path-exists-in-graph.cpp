class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int , vector<int>> gap;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
        }

    }
};