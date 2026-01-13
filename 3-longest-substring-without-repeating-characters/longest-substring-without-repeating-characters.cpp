class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size() == 0) return 0;

        int left = 0;
        int right = 0;
        unordered_map<char, int> map;
        int max_len = INT_MIN;

        while (right < s.size()) {
            if (map.find(s[right]) == map.end()) {
                map[s[right]] = 1;
                max_len = max(max_len, right-left+1);
            } else {
                while (s[left] != s[right]) {
                    map.erase(s[left]);
                    left++;
                }
                left++;
            }

            right++;
        }

        return max_len;
    }
};