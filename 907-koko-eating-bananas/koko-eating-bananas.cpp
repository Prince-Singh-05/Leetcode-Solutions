class Solution {
private:
    long long hoursTaken(vector<int>& piles, int res) {
        long long hours = 0;
        for (int i = 0; i<piles.size(); i++) {
            hours += (piles[i]+res-1)/res;
        }

        return hours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini = 1;
        int maxi = INT_MIN;
        int n = piles.size();

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }

        int ans = maxi;
        while (mini <= maxi) {
            int res = mini + (maxi-mini)/2;
            long long hours_taken = hoursTaken(piles, res);

            if (hours_taken <= h) {
                ans = min(ans, res);
                maxi = res-1;
            } else {
                mini = res+1;
            }
        }

        return maxi+1;
    }
};