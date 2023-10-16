class Solution {

    int maxValue(int piles[]) {

        int max = Integer.MIN_VALUE;

        for(int i = 0; i<piles.length; i++) {
            if(piles[i] > max) {
                max = piles[i];
            }
        }

        return max;
    }

    int hoursForK(int piles[], int k) {
        int hours = 0;

        for(int i = 0; i<piles.length; i++) {
            hours += Math.ceil((double)piles[i]/(double)k);
        }

        return hours;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int s = 1;
        int e = maxValue(piles);
        int ans = 0;

        while(s <= e) {
            int mid = (s+e)/2;

            int res = hoursForK(piles, mid);
            if(res <= h) {
                ans = mid;
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }

        return ans;
    }
}