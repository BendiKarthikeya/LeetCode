class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0;
        for (char ch : s) { 
            ans^=int(ch);
        }
        for (char ch : t) { 
            ans^=int(ch);
        }
        char c=ans;
        return c;
    }
};