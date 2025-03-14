class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n=matrix.size();
        
        int m=matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m, 0));
        for(int j=0;j<m;j++){
            int c=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='0'){
                    c=0;
                }
                else{
                    c++;
                    heights[i][j]=c;
                }
            }
        }
        int area=0;
        for(int i=0;i<n;i++){
            area=max(area,rectange(heights[i]));
        }
        return area;
    }
    int rectange(vector<int>& arr){
        int n=arr.size();
        vector<int> p1(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size()>0 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.size()>0){
                p1[i]=st.top();
            }
            st.push(i);
        }
        stack<int> sts;
        vector<int> p2(n,n);
        for(int i=n-1;i>=0;i--){
            while(sts.size()>0 && arr[sts.top()]>=arr[i]){
                sts.pop();
            }
            if(sts.size()>0){
                p2[i]=sts.top();
            }
            sts.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int w=p2[i]-p1[i]-1;
            int area=w*arr[i];
            ans=max(ans,area);
        }
        return ans;
    }   
};