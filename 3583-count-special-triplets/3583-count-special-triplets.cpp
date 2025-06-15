const int MOD=1e9+7;
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        long long result=0;
        unordered_map<int,int> rights,lefts;
        for(int value:nums){
            rights[value]++;
        }
        for(int j=0;j<nums.size();j++){
            int mid=nums[j];
            rights[mid]--;
            int left=lefts[2*mid];
            int right=rights[2*mid];
            result = (result+1LL*left*right)%MOD;
            lefts[mid]++;
        }
        return result;
    }
};