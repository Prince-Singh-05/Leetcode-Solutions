class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int, int> freqs1;

        for(char ch : s1) {
            freqs1[ch - 'a']++;
        }

        int n1 = s1.length();
        int l = 0, r = n1-1;

        while(r < s2.length()) {

            unordered_map<int, int> freqs2;

            for(int i = l; i<=r; i++) {
                freqs2[s2[i] - 'a']++;
            }

            if(freqs2 == freqs1) {
                return true;
            }

            r++;
            l++;
        }

        return false;
    }
};