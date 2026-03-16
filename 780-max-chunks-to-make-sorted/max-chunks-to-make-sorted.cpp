class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int currMax = -1;
        int res = 0;

        for (int i = 0; i<arr.size(); i++) {
            currMax = max(currMax, arr[i]);

            if (i == currMax) res++;
        }

        return res;
    }
};