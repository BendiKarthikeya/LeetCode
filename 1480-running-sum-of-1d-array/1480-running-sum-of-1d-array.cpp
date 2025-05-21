class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev(n,nums[0]);
        for(int i=1;i<n;i++){
            prev[i]=nums[i]+prev[i-1];
        }
        return prev;
        
    }
};