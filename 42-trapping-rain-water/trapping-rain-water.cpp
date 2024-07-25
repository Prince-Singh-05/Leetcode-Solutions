class Solution {
public:
    int trap(vector<int>& height) {

        // T.C => O(N) + O(N) + O(N) = O(3N) ~ O(N)
        // S.C => O(N) + O(N) = O(2N)
        int n = height.size();
        vector<int> prefix(n);
        vector<int> sufix(n);
        int ans = 0;

        int maxi = 0;
        for(int i = 0; i<n; i++) {
            maxi = max(maxi, height[i]);
            prefix[i] = maxi;
        }

        maxi = 0;
        for(int i = n-1; i>=0; i--) {
            maxi = max(maxi, height[i]);
            sufix[i] = maxi;
        }

        for(int i = 0; i<n; i++) {
            ans += min(prefix[i], sufix[i]) - height[i];
        }

        return ans;
        
    }
};