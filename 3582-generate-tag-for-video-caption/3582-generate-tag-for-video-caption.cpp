class Solution {
public:
    string generateTag(string caption) {
        string s="";
        s='#';
        for(int i=0;i<caption.size();i++){
            if(caption[i]==' ') continue;
            if(i>0 && caption[i-1]==' '){
                if(islower(caption[i])) caption[i]=toupper(caption[i]);
            }
            else{
                if(isupper(caption[i])) caption[i]=tolower(caption[i]);
            }
            s+=caption[i];
        }
        if(s.size() >= 1) s[1] =  tolower(s[1]);
        return s.substr(0,100);
        }
    };