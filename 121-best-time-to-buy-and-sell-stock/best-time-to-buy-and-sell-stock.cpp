class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int maxProfit = 0;
        int i = 0, j = 1;

        while(j < n) {
            if(prices[i] > prices[j]) {
                i = j;
            } else {
                int currProfit = prices[j] - prices[i];
                maxProfit = max(maxProfit, currProfit);
            }

            j++;
        }
        return maxProfit;
    }
};