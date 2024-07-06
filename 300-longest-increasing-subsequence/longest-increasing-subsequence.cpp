class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> lis;
        int len = 1;

        lis.push_back(nums[0]);

        for(int i = 1; i<n; i++) {

            if(nums[i] > lis.back()) {
                lis.push_back(nums[i]);
                len++;
            } else {
                
                int low = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();

                lis[low] = nums[i];
            }
        }
        
        return len;
    }
};