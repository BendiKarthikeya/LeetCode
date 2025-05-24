class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_set<char> us;
    int start=1,end=1;
    int maxs=0;
    while (end < s.length()) {
        if(us.find(s[end])==us.end()){
            us.insert(s[end]);
            maxs=max(maxs,end-start+1);
            end++;
        }
        else{
            us.erase(s[start]);
            start++;
        }
    }
    return maxs;
}
};