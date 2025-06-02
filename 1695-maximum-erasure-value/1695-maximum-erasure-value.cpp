class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        int sum=0;
        int max_sum=0;
        unordered_map<int,int> hm;
        while(j<n){
            if(hm[nums[j]] == 0){
                sum+=nums[j];
                hm[nums[j]]++;
                max_sum=max(sum,max_sum);
                j++;
            }
            else{
                hm[nums[i]]--;
                if(hm[nums[i]]==0){
                    hm.erase(nums[i]);
                }
                sum-=nums[i];
                i++;
            }
        }
        return max_sum;
    }
};