class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        int binary = 0;
        int n = nums.size();
        vector<bool> ans;

        for(int i = 0; i<n; i++) {

            binary = (binary * 2 + nums[i]) % 5;
            ans.push_back(binary == 0);
        }

        return ans;
        
    }
};