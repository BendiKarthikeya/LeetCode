class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int l=0;l<n;l++){
                        if(matrix[l][j]>0){
                            matrix[l][j]*=-1;
                        }
                     }
                    for(int l=0;l<m;l++){
                        if(matrix[i][l]>0){
                            matrix[i][l]*=-1;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0){
                    matrix[i][j]=0;
                }
            }
        }
    }
};