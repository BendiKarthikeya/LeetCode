class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        dfs(image,sr,sc,color,originalColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int originalColor) {
        
        
        if(sr<0 || sc<0 ||sr>=image.size() || sr>=image[0].size() || image[sr][sc] == color || image[sr][sc] != originalColor){
            return;
        }
        int a[]={-1,1,0,0};
        int b[]={0,0,1,-1};
        image[sr][sc]=color;
        for(int l=0;l<4;l++){
            dfs(image,sr+a[l],sc+b[l],color,originalColor);
        }
        
        
        
    }
};