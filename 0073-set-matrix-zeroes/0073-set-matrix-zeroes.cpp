class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> arr;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    arr.push_back({i,j});
                }
            }
        }
        for(int k=0;k<arr.size();k++){
            int i=arr[k].first;
            int j=arr[k].second;
            for(int l=0;l<m;l++){
                matrix[i][l]=0;
            }
            for(int l=0;l<n;l++){
                matrix[l][j]=0;
            }
        }
    }
};