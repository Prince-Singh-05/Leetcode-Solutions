class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 1) return;

        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for (int i = 0; i<nums.size(); i++) {
            if (nums[i] == 0) zeros++;
            else if (nums[i] == 1) ones++;
            else twos++;
        }

        for (int i = 0; i<nums.size(); i++) {
            if (zeros > 0) {
                nums[i] = 0;
                zeros--;
            } else if (ones > 0) {
                nums[i] = 1;
                ones--;
            } else {
                nums[i] = 2;
                twos--;
            }
        }
        
    }
};