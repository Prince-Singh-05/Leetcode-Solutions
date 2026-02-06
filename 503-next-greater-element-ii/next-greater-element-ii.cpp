class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n-1; i>=0; i--) {
            int currElem = nums[i % n];

            while (!st.empty() && st.top() <= currElem) {
                st.pop();
            }

            if (!st.empty() && i < n) {
                ans[i] = st.top();
            }

            st.push(currElem);
        }

        return ans;
    }
};