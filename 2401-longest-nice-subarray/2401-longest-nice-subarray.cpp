class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int bitmask = 0;
        int maxLength = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            while ((bitmask & nums[right]) != 0) {
                bitmask ^= nums[left];
                left++;
            }
            bitmask |= nums[right];
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
