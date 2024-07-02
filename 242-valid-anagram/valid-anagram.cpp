class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        unordered_map<char, int> charCount;

        for (char c : s) {
            charCount[c]++;
        }

        // Decrement counts for characters in t
        for (char c : t) {
            if (charCount.find(c) != charCount.end()) {
                charCount[c]--;
            } else {
                return false; // Character not found in s
            }
        }

        // Check if all counts are zero
        for (const auto& pair : charCount) {
            if (pair.second != 0) {
                return false;
            }
        }
        return true;

        
    }
};