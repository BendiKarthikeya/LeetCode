class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> arr(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
           arr[s[i] - 'a']++;
        }
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                count++;
            }
        }
        int d=count-k;
        if(d<=0){
            return 0;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(arr[i]>0 && d>0){
                 ans+=arr[i];
                 d--;
            }
        }
        return ans;
    }
};