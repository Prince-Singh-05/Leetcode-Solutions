class Solution {
private:
    int findMax(int *arr) {
        int maxi = INT_MIN;

        for (int i = 0; i < 256; i++) {
            maxi = max(maxi, arr[i]);
        }

        return maxi;
    }

public:
    int characterReplacement(string s, int k) {
        int low = 0;
        int freq[256];
        int max_len = INT_MIN;

        for (int high = 0; high < s.size(); high++) {
            freq[s[high]]++;

            int max_count = findMax(freq);
            int len = high-low+1;
            int diff = len - max_count;

            while (diff > k) {
                freq[s[low]]--;
                low++;
                max_count = findMax(freq);
                len = high-low+1;
                diff = len - max_count;
            }

            if (diff <= k) {
                max_len = max(max_len, len);
            }
        }

        return max_len;
    }
};