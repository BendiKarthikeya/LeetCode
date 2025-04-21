class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum=0;
        int rightSum=0;
        for(int i=1;i<nums.size();i++){
            rightSum=rightSum+nums[i];
        }
        int b=0;
        if(rightSum==leftSum){
                return 0;
            }
        for(int i=1;i<nums.size();i++){
            rightSum=rightSum-nums[i];
            leftSum+=nums[b];
            b++;
            if(rightSum==leftSum){
                return i;
            }
        }
        return -1;
    }
};