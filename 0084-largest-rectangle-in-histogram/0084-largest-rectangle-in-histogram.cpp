class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> p1(n,-1);
        vector<int> p2(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            p1[i]=-1;
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()>0){
                p1[i]=st.top();
            }
            st.push(i);
        }
        stack<int> sts;
        for(int i=n-1;i>=0;i--){
            p2[i]=n;
            
            while(sts.size()>0 && heights[sts.top()]>=heights[i]){
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
            int h=heights[i];
            ans=max(ans,w*h);
        }
        return ans;
    }
};