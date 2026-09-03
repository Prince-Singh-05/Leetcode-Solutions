class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) return false;

        unordered_map<char, int> fs;
        unordered_map<char, int> ft;

        for (int i = 0; i<s.length(); i++) {
            fs[s[i]]++;
            ft[t[i]]++;
        }

        for (int i = 0; i<fs.size(); i++) {
            if (fs[i] != ft[i]) return false;
        }

        return true;
    }
};