class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& adj) {
        int n=numCourses;
        unordered_map<int,vector<int>> um;
        vector<int> inc(n,0);
        for(auto& pre : adj) {
            int a=pre[0];
            int b=pre[1];
            um[b].push_back(a);
            inc[a]++;
        }   
        queue<int> que;
        for(int i=0;i<n;i++){
            if(inc[i]==0){
                que.push(i);
            }
        }
        int count=0;
        while(que.size()>0){
            int u=que.front();
            que.pop();
            count++;
                for (int v : um[u]) {
                inc[v]--;
                if (inc[v] == 0) {
                    que.push(v);
                }
            }
        }
        return count==n;
    }
};