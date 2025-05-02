class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int f=0;
        for(int i=0;i<nums.size();i++){
            if(f==0){
                ele=nums[i];
                f++;
            }
            else if(ele==nums[i]){
                f++;
            }
            else{
                f--;
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                count++;
            }
        }
        if(count>nums.size()/2){
            return ele;
        }
        return -1;
    }
};