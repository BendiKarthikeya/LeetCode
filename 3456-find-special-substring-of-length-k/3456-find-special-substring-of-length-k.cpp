class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int count=1;
        int n=s.size();

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                if(count==k){
                    return true;
                }
                count=1;
            }
        }
        return count==k ? true:false;
    }
};