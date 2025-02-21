class Solution {
public:
    bool check(char c) {
        c = tolower(c); 
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(check(s[i]) && check(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            if(!check(s[i])){
                i++;
            }
            if(!check(s[j])){
                j--;
            }

        }
        return s;

    }
    
};