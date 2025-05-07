class Solution {
public:
    int waysToMakeFair(vector<int>& arr) {
        int n = arr.size();
        vector<int> evenSum(n, 0);
        vector<int> oddSum(n, 0);

        int evenSums = 0;
        int oddSums = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenSums += arr[i];
            } else {
                oddSums += arr[i];
            }
            evenSum[i] = evenSums;
            oddSum[i] = oddSums;
        }

        for (int i = 0; i < n; i++) {
            int totalEven = 0, totalOdd = 0;

            if (i == 0) {
                totalEven = oddSum[n - 1] - oddSum[0];
                totalOdd = evenSum[n - 1] - evenSum[0];
            } else {
                totalEven = evenSum[i - 1] + (oddSum[n - 1] - oddSum[i]);
                totalOdd = oddSum[i - 1] + (evenSum[n - 1] - evenSum[i]);
            }

            if (totalEven == totalOdd) {
                count++;
            }
        }

        return count;
    }
};