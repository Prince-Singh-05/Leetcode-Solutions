class Solution {
public:

    void swap(int a, int b, vector<int>& nums) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void sortColors(vector<int>& nums) {
        int l = 0;
        int m = 0; 
        int h = nums.size()-1;

        while(m <= h) {
            if(nums[m] == 0) {
                swap(l, m, nums);
                l++; 
                m++;
            } else if(nums[m] == 1) {
                m++;
            } else {
                swap(m, h, nums);
                h--;
            }
        }
    }
};