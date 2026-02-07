class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> temp(m);
        stack<int> st;
        st.push(nums2[m-1]);
        temp[m-1] = -1;
        unordered_map<int, int> map;
        map[nums2[m-1]] = m-1;

        for (int i = m-2; i >= 0; i--) {
            map[nums2[i]] = i;
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (st.empty()) {
                temp[i] = -1;
            } else {
                temp[i] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> ans(n);

        for (int i = 0; i<n; i++) {
            if (map.find(nums1[i]) != map.end()) {
                ans[i] = temp[map[nums1[i]]];
            }
        }

        return ans;
    }
};