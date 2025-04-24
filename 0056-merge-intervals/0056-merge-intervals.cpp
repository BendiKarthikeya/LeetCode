class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int curri=intervals[0][0];
        int currj=intervals[0][1];
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            int newi=intervals[i][0];
            int newj=intervals[i][1];
            if(max(curri,newi)>min(currj,newj) || currj<newi){
                ans.push_back({curri,currj});
                curri=newi;
                currj=newj;
            }
            else{
                curri=min(curri,newi);
                currj=max(currj,newj);
            }
        }
        ans.push_back({curri,currj});
        return ans;
    }
};