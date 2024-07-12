class Solution {
public:
    bool search(vector<int>& nums, int target) {

        // T.C => O(NlogN)

        // sort(nums.begin(), nums.end());

        // int n = nums.size();
        // int l = 0;
        // int r = n-1;

        // while(l <= r) {

        //     int mid = (r-l)/2 + l;

        //     if(nums[mid] == target) {
        //         return true;
        //     } 
        //     else if(nums[mid] < target) {
        //         l = mid+1;
        //     } else {
        //         r = mid-1;
        //     }
        // }

        // return false;


        // T.C => O(logN)
        
        int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r) {

            int mid = (r-l)/2 + l;

            if(nums[mid] == target) {
                return true;
            }
            
            if(nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l = l+1;
                r = r-1;
                continue;
            }

            if(nums[l] <= nums[mid]) {
                if(nums[l] <= target && target <= nums[mid]) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            else {
                if(nums[mid] <= target && target <= nums[r]) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
        }

        return false;
        
    }
};