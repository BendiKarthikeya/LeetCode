class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int , vector<int>> gap;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            gap[u].push_back(v);
            gap[v].push_back(u);
        }
        queue<int> que;
        unordered_set<int> vist;

        que.push(source);
        vist.insert(source);

        while(!que.empty()){
            int node=que.front();
            que.pop();
            if(node==destination){
                return true;
            }
            for(int temp:gap[node]){
                if(vist.find(temp)==vist.end()){
                    vist.insert(temp);
                    que.push(temp);
                }

            }
        }
        return false;

    }
};