class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        int count = 0;

        for (int i = 0; i<nums.size(); i++) {

            while (!st.empty() && nums[i] < st.top()) {
                st.pop();
            }

            if (nums[i] != 0 && (st.empty() || nums[i] > st.top())) {
                st.push(nums[i]);
                count++;
            }
        }

        return count;
    }
};