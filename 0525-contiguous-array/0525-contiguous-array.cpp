class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> sumIndex;
        sumIndex[0]=-1;
        int sum=0;
        int maxLength=0;
        for(int i=0;i<nums.size();i++){
            sum+= (nums[i]==1) ? 1 : -1;
            if(sumIndex.find(sum) != sumIndex.end()){
                maxLength=max(maxLength,i-sumIndex[sum]);
            }
            else{
                sumIndex[sum]=i;
            }

        }
        return maxLength;
    }
};