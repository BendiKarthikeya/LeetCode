class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int res=1;
        int i=0,j=0;
        while(n>1){
            for(int l=0;l<=n-2;l++){
                matrix[i][j]=res;
                j++;
                res++;
            }
            for(int l=0;l<=n-2;l++){
                matrix[i][j]=res;
                i++;
                res++;
            }
            for(int l=0;l<=n-2;l++){
                matrix[i][j]=res;
                j--;
                res++;
            }
            for(int l=0;l<=n-2;l++){
                matrix[i][j]=res;
                i--;
                res++;
            }
            i++;
            j++;
            n=n-2;
        }
        if(n==1){
            matrix[i][j]=res;
        }
        return matrix;
    }
};