class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (char c : ransomNote) {
            if (map1.find(c) == map1.end()) {
                map1[c] = 1;
            } else {
                map1[c]++;
            }
        }

        for (char c : magazine) {
            if (map2.find(c) == map2.end()) {
                map2[c] = 1;
            } else {
                map2[c]++;
            }
        }

        for (char c : ransomNote) {
            if (map1[c] > map2[c]) {
                return false;
            }
        }

        return true;
    }
};