class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index!=-1){
        for(int j=n-1;j>index;j--){
            if(nums[j]>nums[index]){
                swap(nums[j],nums[index]);
                break;
            }
        }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};