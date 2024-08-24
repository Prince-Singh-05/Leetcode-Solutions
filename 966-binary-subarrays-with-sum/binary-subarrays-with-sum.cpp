class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return subarrayWithSum(nums, goal) - subarrayWithSum(nums, goal-1);
    }

private:
    int subarrayWithSum(vector<int>& nums, int goal) {
        
        if(goal < 0) return 0;
        int count = 0;
        int l = 0, r = 0;
        int currSum = 0;

        while(r < nums.size()) {
            currSum += nums[r];

            while(currSum > goal) {
                currSum -= nums[l];
                l++;
            }

            count = count + r-l+1;
            r++;
        }

        return count;
    }

};