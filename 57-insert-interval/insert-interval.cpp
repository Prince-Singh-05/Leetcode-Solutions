class Solution {
private:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int start1 = arr[0][0];
        int end1 = arr[0][1];
        vector<vector<int>> res;

        for(int i = 1; i<n; i++) {
            int start2 = arr[i][0];
            int end2 = arr[i][1];

            if (end1 >= start2) {
                end1 = max(end1, end2);
                continue;
            }

            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        res.push_back({start1, end1});
        return res;
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> newIntervals = intervals;
        newIntervals.push_back(newInterval);

        return mergeIntervals(newIntervals);
    }
};