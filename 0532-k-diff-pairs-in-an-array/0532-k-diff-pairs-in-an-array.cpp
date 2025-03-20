class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<pair<int,int>> count;
        int s=0;
        int l=1;
        while(l<n){
            int dif=nums[l]-nums[s];
            if(dif==k){
                count.insert({nums[s],nums[l]});
                ++s;
                ++l;
            }
            else if(dif>k){
                s++;
            }
            else{
                l++;
            }
            if(s==l){
                l++;
            }
        }
        return count.size();
    }
};