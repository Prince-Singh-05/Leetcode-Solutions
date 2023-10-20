class Solution {
public:

    bool lessThanThreshold(vector<int>& nums, int div, int threshold) {
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++) {
            sum += ceil((double) (nums[i]) / (double) (div));
        }

        return sum<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        int n = nums.size();

        if(n > threshold) return -1;

        for(int i : nums) {
            maxi = max(maxi, i);
        }

        int s = 1, e = maxi;

        cout << s << " " << e << endl;
        cout << 11/22 << endl;

        while(s <= e) {
            int mid = (s+e)/2;

            if(lessThanThreshold(nums, mid, threshold)) {
                e = mid-1;
            } else {
                s = mid+1;
            }
        }

        return s;
    }
};