class Solution {
public:
    int jump(vector<int>& nums) {

        int len = nums.size();

        if(len == 1) return 0;

        int mini = 0;
        int maxi = 0;

        int jump = 0;

        while(maxi < len-1) {

            int farthest = 0;

            for(int i = mini; i<=maxi; i++) {
                farthest = max(farthest, i+nums[i]);
            }

            mini = maxi+1;
            maxi = farthest;
            jump++;
        }
        
        return jump;
    }
};