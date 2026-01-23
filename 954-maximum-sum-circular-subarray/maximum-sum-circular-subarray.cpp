class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int largest = nums[0];
        int smallest = nums[0];
        int total_sum = nums[0];
        int largest_ans = nums[0];
        int smallest_ans = nums[0];
        int n = nums.size();

        for (int i = 1; i<n; i++) {
            int opt1 = largest + nums[i];
            int opt2 = nums[i];
            largest = max(opt1, opt2);
            largest_ans = max(largest_ans, largest);
            total_sum += nums[i];
        }

        cout << "largest: " << largest_ans << endl;

        for (int i = 1; i<n; i++) {
            int opt1 = smallest + nums[i];
            int opt2 = nums[i];
            smallest = min(opt1, opt2);
            smallest_ans = min(smallest_ans, smallest);
        }

        cout << "smallest: " << smallest_ans << endl;

        return (total_sum == smallest_ans) ? largest_ans : max(largest_ans, total_sum - smallest_ans);
    }
};