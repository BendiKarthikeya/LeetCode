class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        vector<vector<int>> result = {{rStart, cStart}};
        int d=0;
        int steps=0;
        while(result.size()< rows*cols){
            if (d==0 || d==2){
                steps++;
            }
            for(int i=1;i<=steps;i++){
                rStart+=dir[d][0];
                cStart+=dir[d][1];
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                     result.push_back({rStart,cStart});
                }
                if(result.size()== rows*cols) return result; 
            }
            d=(d+1)%4;

        }
        return result;
    }
};