class Solution {
private:
    int startPoint(vector<int>& nums, int target, int start, int end) {
        int res_idx = -1;

        while (start <= end) {
            int mid = start + (end-start)/2;

            if (nums[mid] == target) {
                res_idx = mid;
                end = mid-1;
            } else if (nums[mid] < target) {
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        return res_idx;
    }

    int endPoint(vector<int>& nums, int target, int start, int end) {
        int res_idx = -1;

        while (start <= end) {
            int mid = start + (end-start)/2;

            if (nums[mid] == target) {
                res_idx = mid;
                start = mid+1;
            } else if (nums[mid] > target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }

        return res_idx;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        vector<int> res(2);
        
        res[0] = startPoint(nums, target, start, end);
        res[1] = endPoint(nums, target, start, end);

        return res;
    }
};