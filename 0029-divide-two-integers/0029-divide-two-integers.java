class Solution {
    public int divide(int dividend, int divisor) {

        if (divisor == Integer.MIN_VALUE) {
            return dividend == Integer.MIN_VALUE ? 1 : 0;
        }

        if (dividend == 0) {
            return 0;
        }

        if (dividend == Integer.MIN_VALUE) {
            if (divisor == 1) {
                return Integer.MIN_VALUE;
            } else if (divisor == -1) {
                return Integer.MAX_VALUE;
            }
        }

        boolean sign = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = true;
        }

        if (dividend > 0) {
            dividend = -dividend;
        }

        if (divisor > 0) {
            divisor = -divisor;
        }

        int MAX = Integer.MIN_VALUE >> 1;
        int ans = 0;

        // dividend became negative
        while (dividend <= divisor) {
            int temp = divisor;
            int step = -1;

            while (temp >= MAX && step >= MAX && temp >= dividend - temp) {
                temp += temp;
                step += step;
            }

            dividend -= temp;
            ans += step;
        }
        
        // int newDivisor = Math.abs(divisor);
        // int newDividend = Math.abs(dividend);
        // int s = 0;
        // int e = newDividend;
        // int ans = 0;

        // while(s <= e) {
        //     int mid = s+(e-s)/2;

        //     if(mid*newDivisor == newDividend) {
        //         ans = mid;
        //         break;
        //     } else if(mid*newDivisor < newDividend) {
        //         ans = mid;
        //         s = mid+1;
        //     } else {
        //         e = mid-1;
        //     }
        // }

        return sign ? ans : -ans;

    }
}