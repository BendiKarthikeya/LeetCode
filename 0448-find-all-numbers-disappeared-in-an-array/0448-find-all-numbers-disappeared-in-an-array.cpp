class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]!=i+1){
                int ele=nums[i];
                int ind=ele-1;
                if(ind<0 || ind>n){
                    break;
                }
                if(nums[i]==nums[ind]){
                    break;
                }
                swap(nums[i],nums[ind]);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};