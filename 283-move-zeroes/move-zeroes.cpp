class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return;

        int i = 0;
        int j = 1;

        while(i<n && j<n) {

            if(nums[i] == 0) {

                if(nums[j] != 0) {
                    swap(nums[i], nums[j]);
                    i++;
                    j++;
                }
                else {
                    j++;
                }
            }
            else {
                i++;
                j=i+1;
            }
        }
    }
};