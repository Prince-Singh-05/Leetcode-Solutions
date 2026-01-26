class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int res = 0;

        unordered_map<int, int> freq;
        freq[0] = 1;

        for (int i = 0; i<n; i++) {
            sum += nums[i];
            int x = sum%k;
            if (x < 0) x = x+k;
            res += freq[x];
            freq[x]++;
        }

        return res;
    }
};