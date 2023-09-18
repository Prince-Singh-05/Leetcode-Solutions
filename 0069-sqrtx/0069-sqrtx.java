class Solution {
    public int mySqrt(int x) {
        int s = 0;
        int e = x;
        int ans = -1;

        while(s <= e) {
            long mid = s + (e-s)/2;

            if(mid*mid == x) {
                return (int)mid;
            }

            if(mid*mid > x) {
                e = (int)mid-1;
            } else {
                ans = (int)mid;
                s = (int)mid+1;
            }
        }

        return ans;
    }
}