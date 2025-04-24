class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int curri=newInterval[0];
        int currj=newInterval[1];
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            int newi=intervals[i][0];
            int newj=intervals[i][1];
            if(max(curri,newi)>min(currj,newj) || currj<newi){
                ans.push_back({newi,newj});
            }
            else{
                curri=min(curri,newi);
                currj=max(currj,newj);
            }
        }
        ans.push_back({curri,currj});
        sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        return ans;
    }
};