class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int res = arr[0];
        int res_idx = 0;
        int n = arr.size();

        for (int i = 1; i<n; i++) {
            if (arr[i] < res) {
                return res_idx;
            } else {
                res = arr[i];
                res_idx = i;
            }
        }
        
        return res_idx;
    }
};