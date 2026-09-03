class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        unordered_map<char, int> fs;
        unordered_map<char, int> ft;

        for (int i = 0; i < s.length(); i++) {
            fs[s[i]]++;
            ft[t[i]]++;
        }

        for (auto& pair : fs) {
            if (pair.second != ft[pair.first]) {
                return false;
            }
        }

        return true;
    }
};