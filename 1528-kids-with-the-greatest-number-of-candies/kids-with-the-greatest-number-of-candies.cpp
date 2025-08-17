class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int maxi = -1;
        vector<bool> ans;

        for(int i = 0; i<candies.size(); i++) {
            maxi = max(maxi, candies[i]);
        }

        for(int i = 0; i<candies.size(); i++) {
            int newValue = candies[i]+extraCandies;
            if(newValue >= maxi) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};