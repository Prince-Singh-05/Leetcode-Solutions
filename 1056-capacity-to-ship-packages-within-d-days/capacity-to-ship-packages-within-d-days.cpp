class Solution {
private:
    bool possible(vector<int>& weights, int days, int guess) {
        int required_days = 1;
        int current_load = 0;

        for (int i = 0; i<weights.size(); i++) {
            if (current_load + weights[i] > guess) {
                required_days++;
                current_load = weights[i];
            } else {
                current_load += weights[i];
            }
        }

        return required_days <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int start = 0;
        int end = 0;

        for (int w: weights) {
            end += w;
            start = max(start, w);
        }

        int res = end;

        while (start <= end) {
            int mid = start + (end-start)/2;

            if (possible(weights, days, mid)) {
                res = mid;
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return res;
    }
};