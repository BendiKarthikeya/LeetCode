class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            if(nums[i]<1 || nums[i]>=nums.size()){
                i++;
                continue;
            }
            if(nums[i]-1==i || nums[i]==nums[nums[i]-1]){
                i++;
                continue;
            }
            else{
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i+1!=nums[i]){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};