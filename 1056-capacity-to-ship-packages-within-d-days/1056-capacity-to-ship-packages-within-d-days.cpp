class Solution {
public:

    bool validShipCapacity(vector<int>& weights, int capacity, int days) {
        int noOfD = 1;
        int thisShip = 0;

        for(int w : weights) {
            if((thisShip + w) <= capacity) {
                thisShip += w;
            } else {
                thisShip = w;
                noOfD += 1;
            }
        }

        if(thisShip <= capacity && noOfD <= days) {
            return true;
        }

        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum = 0;

        for(int i : weights) {
            sum += i;
            maxi = max(maxi, i);
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
};