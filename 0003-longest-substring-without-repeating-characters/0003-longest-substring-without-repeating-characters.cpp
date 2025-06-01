class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=1;
        int n=s.size();
        unordered_map<char,int> hm;
        int len=0;
        while(j<n){
            if(j-i+1==hm.size()){
                len=max(len,j-i+1);
                j++;
                if(j==n){
                    break;
                }
                hm[s[i]]++;
            }
            else{
                hm[s[i]]--;
                if(hm[s[i]]==0){
                    hm.erase(s[i]);
                }
                i++;
            }
        }
        return len;
    }
};