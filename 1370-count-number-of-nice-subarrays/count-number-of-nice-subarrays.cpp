class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return subarrayCount(nums, k) - subarrayCount(nums, k -1);
    }

private: 
    int subarrayCount(vector<int>& nums, int k) {

        if(k < 0) return 0;

        int l = 0, r = 0;
        int count = 0;
        int sum = 0;

        while(r < nums.size()) {

            sum += (nums[r] % 2);

            while(sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }

            count = count + r-l+1;
            r++;
        }

        return count;
    }
};