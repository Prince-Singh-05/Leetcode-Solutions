class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> dq;

        // first window
        for(int i = 0; i<k; i++) {
            int el = nums[i];

            while(!dq.empty() && el > nums[dq.back()]) {
                dq.pop_back();
            }

            // add
            dq.push_back(i);
        }

        // remaining window
            // removal
            // additon

        for(int i = k; i<nums.size(); i++) {

            // store ans
            ans.push_back(nums[dq.front()]);

            // removal
            // out of range

            if(!dq.empty() && i-dq.front() >= k) {
                dq.pop_front();
            }

            // chote element
            int el = nums[i];
            while(!dq.empty() && el > nums[dq.back()]) {
                dq.pop_back();
            }

            // addition
            dq.push_back(i);
        }
        
        // last window
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};