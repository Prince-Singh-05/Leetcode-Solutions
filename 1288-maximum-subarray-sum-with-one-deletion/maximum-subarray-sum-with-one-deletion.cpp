class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int no_delete = arr[0];
        int one_delete = INT_MIN;
        int res = arr[0];

        for (int i = 1; i<arr.size(); i++) {
            int prev_no_delete = no_delete;
            int prev_one_delete = one_delete;

            no_delete = max(no_delete + arr[i], arr[i]);

            int opt;
            if (prev_one_delete == INT_MIN)
                opt = arr[i];
            else
                opt = prev_one_delete + arr[i];

            one_delete = max(opt, prev_no_delete);

            res = max(res, max(no_delete, one_delete));
        }

        return res;
    }
};