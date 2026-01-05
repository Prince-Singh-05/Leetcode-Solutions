class Solution {
private:
    void twoSum(int i, int left, int right, int sum, vector<int>& nums, vector<vector<int>>& res) {
        while (left < right) {
            int s = nums[left] + nums[right];
            if (s == sum) {
                vector<int> temp = {nums[i], nums[left], nums[right]};
                res.push_back(temp);
                left++;
                right--;

                while (left < nums.size() && nums[left] == nums[left-1]) left++;
                while (right >= 0 && nums[right] == nums[right+1]) right--;
            } else if (s < sum) {
                left++;
            } else right--;
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = n-1;
            int sum = (-1) * nums[i];

            twoSum(i, left, right, sum, nums, res);
        }

        return res;
    }
};