class Solution {
public:
    int smallestDivisor(vector<int>& arr, int threshold) {
        int n = arr.size();
        int low = 1;
        
        int high = INT_MIN;
        for(int i=0;i<n;i++){
            high=max(high,arr[i]);
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (arr[i] + mid-1)/mid;
            }
            if (sum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};