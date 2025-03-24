class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> arr;
        vector<vector<int>> vec(n,vector<int>(n, 0));
        ansQueens(n,arr,0,vec);
        return arr;
    }
    void ansQueens(int n,vector<vector<string>>& arr,int i,vector<vector<int>>& vec)   {
        if(i==n){
            vector<string> arr2;
            for(int i=0;i<n;i++){
                string str="";
                for(int j=0;j<n;j++){
                    if(vec[i][j]==1){
                        str+="Q";
                    }
                    else{
                        str+=".";
                    }  
                }
                arr2.push_back(str);
            }
            arr.push_back(arr2);
            return;
        }
        for(int k=0;k<n;k++){
            if(valid(vec,i,k,n)){
                vec[i][k]=1;
                ansQueens(n,arr,i+1,vec);
                vec[i][k]=0;
            }
        }
        return;
    }
    bool valid(vector<vector<int>>& vec,int i,int k,int n){
        int r=i,c=k;
        while(r>=0){
            if(vec[r][c] == 1){
                return false;   
            }
            r--;
        }
        r=i,c=k;
        while(r>=0 && c>=0){
            if(vec[r][c]==1){
                return false;   
            }
            r--;c--;
        }
        r=i,c=k;
        while(r>=0 && c<n){
            if(vec[r][c]==1){
                return false;   
            }
            r--;c++;
        }
        return true;
    }
};