class Solution {
public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
       for(int i=0;i<4;i++){
        int n=matrix.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }   
            for(int i=0;i<n;i++){
                for(int j=0;j<n/2;j++){
                    swap(matrix[i][j],matrix[i][n-j-1]);
                }
            }
            int count=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==target[i][j]){
                        count++;
                    }
                }
            }
            if(count==n*n){
                return true;
            }
       }
       return false;
    }
};