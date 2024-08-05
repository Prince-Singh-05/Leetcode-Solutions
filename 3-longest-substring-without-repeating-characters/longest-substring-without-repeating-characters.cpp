class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> letters;
        
        int i = 0;
        int j = 0;
        
        int maxLen = 0;
        
        while (j < s.size()) {
            if (letters.find(s[j]) == letters.end()) {
                letters.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else {
                letters.erase(s[i]);
                i++;
            }
        }
        
        return maxLen;
        
    }
};