class Solution {
public:

    void swap(int a, int b, vector<int>& nums) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int count = 0;

        while(j < nums.size()) {
            if(nums[i] >= nums[j]) {
                ++j;
            } else {
                swap(i+1, j, nums);
                ++i;                
            }
        }

        for(int idx = 0; idx <= i; ++idx) {
            ++count;
        }

        return count;
    }
};