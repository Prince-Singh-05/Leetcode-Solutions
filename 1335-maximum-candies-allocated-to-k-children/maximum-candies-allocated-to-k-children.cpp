class Solution {
private:
    bool possible(vector<int>& candies, long long k, int guess) {
        if (guess == 0) return true;

        long long noOfStdGetCandies = 0;
        for (int i = 0; i<candies.size(); i++) {
            noOfStdGetCandies += (long long) candies[i]/guess;
        }

        return noOfStdGetCandies >= k ? true : false;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxi = INT_MIN;

        for (int i = 0; i<n; i++) {
            maxi = max(maxi, candies[i]);
        }

        int start = 0;
        int end = maxi;
        int res = 0;

        while (start <= end) {
            int mid = start + (end-start)/2;

            if (possible(candies, k, mid)) {
                res = mid;
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        return res;
    }
};