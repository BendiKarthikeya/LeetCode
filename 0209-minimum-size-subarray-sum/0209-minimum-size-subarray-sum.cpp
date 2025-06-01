class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N=nums.size();
        int i=0,j=0,sum=nums[0];
        int l=INT_MAX;
        while(j<N){
            if(sum>=target){
                l=min(j-i+1,l);
                sum=sum-nums[i];
                i++;
            }
            else{
                j++;
                if(j==N){
                    break;
                }
                sum=sum+nums[j];
            }
        }
        return l==INT_MAX ? 0 : l;
    }
};