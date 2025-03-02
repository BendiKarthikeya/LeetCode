class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int h=nums.size()-1;
        int count=0;
        while(l<h){
            int sum=nums[l]+nums[h];

            if(sum==k){
                count++;
                l++;
                h--;

            }
            else if(sum<k){
                l++;
            }
            else{
                h--;
            }

        }
        return count;
    }
};