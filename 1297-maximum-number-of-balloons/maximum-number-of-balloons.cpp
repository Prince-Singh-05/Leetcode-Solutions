class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> um;

        for (char c : text) {
            if (um.find(c) == um.end()) {
                um.insert({c, 1});
            } else {
                um[c]++;
            }
        }

        int count = 0;

        while (um['b'] >= 1 && um['a'] >= 1 && um['l']>=2 && um['o'] >= 2 && um['n'] >= 1) {
            count++;
            um['b']--;
            um['a']--;
            um['l'] -= 2;
            um['o'] -= 2;
            um['n']--;
        }

        return count;
    }
};