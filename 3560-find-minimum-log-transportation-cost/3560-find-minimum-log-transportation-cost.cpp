class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) return 0;

        int extraRows = max(0, n - k);
        int extraCols = max(0, m - k); 
        
        return (long long)(extraRows + extraCols) * k;
    }
};
