class Solution {
public:

    bool possible(vector<int>& arr, int days, int weight) {
        int currentLoad = 0;
        int requiredDays = 1;
        for(int itemWeight : arr) {
            if(currentLoad + itemWeight > weight) {
                currentLoad = itemWeight;
                requiredDays++;
                if(requiredDays > days) return false;
            } else {
                currentLoad += itemWeight;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int minCapacity = *max_element(weights.begin(), weights.end());
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);
        int answer = maxCapacity;

        while(minCapacity <= maxCapacity) {
            int midCapacity = (minCapacity + maxCapacity) / 2;
            if(possible(weights, days, midCapacity)) {
                answer = midCapacity;
                maxCapacity = midCapacity - 1;
            } else {
                minCapacity = midCapacity + 1;
            }
        }
        return answer;
    }
};
