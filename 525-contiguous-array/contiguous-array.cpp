class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        unordered_map<int, int> map;
        int res = 0;

        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] == 0) zero++;
            else one++;

            int diff = zero - one;

            if (diff != 0) {
                if (map.count(diff)) {
                    int ind = map[diff];
                    res = max(res, i-ind);
                } else {
                    map[diff] = i;
                }
            } else {
                res = max(res, i+1);
            }
        }

        return res;
    }
};