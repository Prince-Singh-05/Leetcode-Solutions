class Solution {

    boolean validShipCapacity(int weights[], int capacity,int days) {
        int thisShip = 0;
        int n = weights.length;
        int noOfD = 1;

        for(int i = 0; i<n; i++) {
            if((thisShip + weights[i]) <= capacity) {
                thisShip += weights[i];
            } else {
                thisShip = weights[i];
                noOfD += 1;
            }
        }

        if(thisShip <= capacity && noOfD <= days) {
            return true;
        }

        return false;
    }

    public int shipWithinDays(int[] weights, int days) {
        int maxi = Integer.MIN_VALUE;
        int sum = 0;

        for(int i : weights) {
            sum += i;
            maxi = Math.max(maxi, i);
        }

        int s = maxi, e = sum;

        while(s <= e) {
            int mid = (s+e)/2;

            if(validShipCapacity(weights, mid, days)) {
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return s;
    }
}