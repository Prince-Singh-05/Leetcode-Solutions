class Solution {
private:
    void prefixSum(vector<int>& arr, vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            arr[i] = arr[i-1] + nums[i-1];
        }
    }
    
    void sufixSum(vector<int>& arr, vector<int>& nums) {
        for (int i = nums.size()-2; i >= 0; i--) {
            arr[i] = arr[i+1] + nums[i+1];
        }
    }

public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> sufix(n);

        prefixSum(prefix, nums);
        sufixSum(sufix, nums);

        for (int i = 0; i<n; i++) {
            if (prefix[i] == sufix[i]) return i;
        }

        return -1;
    }
};