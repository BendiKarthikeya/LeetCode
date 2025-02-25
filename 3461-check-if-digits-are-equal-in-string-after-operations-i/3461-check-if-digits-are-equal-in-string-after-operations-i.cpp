class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string a="";
            for(int i=0;i<s.size()-1;i++){
                int b= ((s[i] - '0')+(s[i+1] - '0'))% 10;
                a=a+to_string(b);
            }   
            s=a;
        }
        return s.size() == 2 && s[0] == s[1];  
    }
};