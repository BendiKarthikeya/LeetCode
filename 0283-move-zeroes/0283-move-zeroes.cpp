class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start=0;
        int end=0;
        while(end<nums.size()){
            if(nums[start]==0 && nums[end]!=0){
                swap(nums[start],nums[end]);
            }
            else if(nums[start]==0 && nums[end]==0){
                end++;
            }
            else if(nums[start]!=0){
                start++;
            }
        }
    }
};