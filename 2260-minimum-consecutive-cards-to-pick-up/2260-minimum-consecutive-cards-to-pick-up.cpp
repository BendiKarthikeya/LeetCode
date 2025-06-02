class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int i=0,j=-1;
        int l=INT_MAX;
        unordered_map<int,int> hm;
        int n=cards.size();
        while(j<n){
            if(j-i+1==hm.size()){
                j++;
                if(j==n){
                    break;
                }
                hm[cards[j]]++;
            }
            else{
                l=min(l,j-i+1);
                hm[cards[i]]--;
                i++;
                
            }
        }
        return l==INT_MAX ? -1 : l;
    }
};