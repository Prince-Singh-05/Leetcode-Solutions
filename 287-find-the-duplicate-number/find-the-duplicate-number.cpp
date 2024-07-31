class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Circular Linked List Concept with Floyd's Algorithm
        // T.C => O(N) && S.C => (1)
        
        int slow = nums[0];
        int fast = nums[nums[0]];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};