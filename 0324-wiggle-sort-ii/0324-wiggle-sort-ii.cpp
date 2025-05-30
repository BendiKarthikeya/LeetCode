class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(),sorted.end());
        int n = nums.size();
        int mid = (n + 1) / 2; 
        int k=n-1;
        int j=mid-1;
        for(int i=0;i<nums.size();i++){
            nums[i]= i%2==0 ? sorted[j--] : sorted[k--];
        }
    }
};