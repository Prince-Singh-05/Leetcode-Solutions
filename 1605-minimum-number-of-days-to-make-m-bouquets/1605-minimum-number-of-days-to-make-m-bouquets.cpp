class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int noOfB = 0;
        int cnt = 0;
        int n = bloomDay.size();

        for(int i = 0; i<n; i++) {
            if(bloomDay[i] <= day) {
                cnt++;
            } else {
                noOfB += (cnt/k);
                cnt = 0;
            }
        }

        noOfB += (cnt/k);

        return noOfB>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();
        long val = (long) m * k;
        if(val > n) {
            return -1;
        }

        int mini = INT_MAX, maxi = INT_MIN;

        for(int i = 0; i<n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int s = mini, e = maxi;

        while(s <= e) {
            int mid = (s+e)/2;

            if(possible(bloomDay, mid, m, k)) {
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return s;
    }
};