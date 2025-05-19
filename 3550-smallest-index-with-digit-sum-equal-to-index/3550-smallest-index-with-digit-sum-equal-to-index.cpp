class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(sumOfDigits(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
    int sumOfDigits(int a){
        int sum=0;
        while(a>0){
            sum+=a%10;
            a=a/10;
        }
        return sum;
    }
};