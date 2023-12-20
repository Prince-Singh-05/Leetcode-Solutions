class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i<k; i++) {
            int element = nums[i];
            pq.push(element);
        }

        for(int i = k; i<n; i++) {
            int element = nums[i];
            if(element > pq.top()) {
                pq.pop();
                pq.push(element);
            }
        }

        return pq.top();
    }
};