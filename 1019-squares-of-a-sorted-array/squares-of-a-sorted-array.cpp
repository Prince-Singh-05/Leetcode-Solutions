class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> neg;
        vector<int> pos;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            int sqr = nums[i]*nums[i];
            if (nums[i] < 0) {
                neg.push_back(sqr);
            } else {
                pos.push_back(sqr);
            }
        }

        sort(neg.begin(), neg.end());

        int i = 0;
        int j = 0;

        while (i < neg.size() && j < pos.size()) {
            if (neg[i] <= pos[j]) {
                res.push_back(neg[i]);
                i++;
            } else {
                res.push_back(pos[j]);
                j++;
            }
        }

        while (i < neg.size()) {
            res.push_back(neg[i++]);
        }

        while (j < pos.size()) {
            res.push_back(pos[j++]);
        }

        return res;
    }
};