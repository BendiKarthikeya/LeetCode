class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> p1(n,-1);
        vector<int> p2(n,n);
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
        for(int i=n-1;i>=0;i--){
            while(sts.size()>0 && arr[sts.top()]>=arr[i]){
                sts.pop();
            }
            if(sts.size()>0){
                p2[i]=sts.top();
            }
            sts.push(i);
        }
        long long min_Sum=0;
        for(int i=0;i<n;i++){
            long long start=i-p1[i], end=p2[i]-i;
            min_Sum+=start*end*arr[i];
             min_Sum= min_Sum%1000000007;
        }

        return min_Sum;
    }
};