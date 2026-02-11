class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        for (char c: s) {
            if (freq.find(c) == freq.end()) {
                freq.insert({c, 1});
            } else {
                freq[c]++;
            }
        }

        for (int i = 0; i<s.size(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};