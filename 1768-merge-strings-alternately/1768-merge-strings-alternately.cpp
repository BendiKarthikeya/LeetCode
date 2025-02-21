class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str="";
        int i=word1.size();
        int j=word2.size();
        int maxLength=max(i,j);
        for(int i=0;i<maxLength;i++){
            if(i<word1.size()){
                str+=word1[i];
            }
             if(i<word2.size()){
                str+=word2[i];
            }
        }
        return str;
    }
};