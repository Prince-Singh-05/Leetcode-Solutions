class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int left = 1;
        int right = INT_MIN;

        for(int i = 0; i<piles.size(); i++) {
            right = max(right, piles[i]);
        }

        int ans = right;
        while(left <= right) {
            int mid = left + (right-left)/2;
            long long hoursForMid = calculateHours(piles, mid);

            if(hoursForMid > h) {
                left = mid+1;
            } else {
                ans = min(ans, mid);
                right = mid-1;
            }
        }
        
        return ans;
    }

private:
    long long calculateHours(vector<int>& piles, int mid) {

        long long totalHours = 0;

        for(int i = 0; i<piles.size(); i++) {

            int hoursToEatPile = piles[i]/(double)mid;

            if(piles[i]%mid == 0) {
                totalHours += hoursToEatPile;
            } else {
                totalHours += hoursToEatPile + 1;
            }
        }

        return totalHours;
    }

};
