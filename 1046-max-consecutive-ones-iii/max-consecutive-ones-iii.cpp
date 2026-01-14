class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int freq[2];
        int max_len = INT_MIN;

        for (int high = 0; high < nums.size(); high++) {
            freq[nums[high]]++;

            int len = high-low+1;

            while (freq[0] > k) {
                freq[nums[low]]--;
                low++;

            }

            if (freq[0] <= k) {
                len = high-low+1;
                max_len = max(max_len, len);
            }
        }

        return max_len;
    }
};