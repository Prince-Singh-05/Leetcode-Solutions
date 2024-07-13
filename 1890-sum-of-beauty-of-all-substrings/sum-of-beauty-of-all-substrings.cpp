class Solution {
public:
    int beautySum(string s) {

        int ans = 0;

        for(int i = 0; i<s.length()-1; i++) {

            vector<int> freq(26, 0);
            freq[s[i]-'a']++;

            for(int j = i+1; j < s.length(); j++) {

                freq[s[j] - 'a']++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(int k = 0; k<26; k++) {
                    if(freq[k] > 0) {
                        mini = min(mini, freq[k]);
                        maxi = max(maxi, freq[k]);
                    }
                }

                ans += maxi-mini;
            } 
        }

        return ans;
        
    }
};