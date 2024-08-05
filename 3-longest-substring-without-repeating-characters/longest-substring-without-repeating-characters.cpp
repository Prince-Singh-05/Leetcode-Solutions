class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        if(n == 0) return 0;
        if(n == 1) return 1;

        int i = 0, j = 1;
        unordered_map<char, int> uniq;
        int maxLen = 1;
        uniq[s[i]]++;
        int count = 1;

        while(i < n) {    

            if(j == n) {
                break;
            }

            uniq[s[j]]++;
            if(uniq[s[j]] > 1) {
                uniq.clear();
                count = 1;
                i++;
                j = i;
                uniq[s[j]]++;
            }
            else {
                ++count;
                maxLen = max(maxLen, count);
            }

            j++;
        }

        return maxLen;
        
    }
};