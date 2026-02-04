class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans;
        unordered_map<int, int> map;

        for (int i = 0; i<m; i++) {
            map.insert({nums2[i], i});
        }

        for (int i = 0; i<n; i++) {
            int j = map[nums1[i]];
            j++;
            
            while (j < m) {
                if (nums2[j] > nums1[i]) {
                    ans.push_back(nums2[j]);
                    break;
                }

                j++;
            }
            
            if (j >= m) ans.push_back(-1);
            
        }

        return ans;
    }
};