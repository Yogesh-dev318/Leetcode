class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int requiredDays = 1;
        int currentWeight = 0;
        for (int weight : weights) {
            if (currentWeight + weight <= capacity) {
                currentWeight += weight;
            } else {
                requiredDays++;
                currentWeight=weight;
            }
        }
        return requiredDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        for (int weight : weights) {
            low = max(low, weight);
            high += weight;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};