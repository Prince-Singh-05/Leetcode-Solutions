class Solution {
public:
    string minWindow(string s, string t) {
        int freqT[256] = {0};
        int l = 0, r = 0, minLen = INT_MAX, start = -1, cnt = 0;

        for(int i = 0; i<t.length(); i++) {
            freqT[t[i]]++;
        }

        while(r < s.length()) {
            if(freqT[s[r]] > 0) {
                cnt += 1;
            }
            freqT[s[r]]--;
            
            while (cnt == t.length()) {
                if(r-l+1 < minLen) {
                    minLen = r-l+1;
                    start = l;
                }
                
                freqT[s[l]]++;
                if(freqT[s[l]] > 0) cnt -= 1;

                l++;
            }

            r++;
        }
        

        return (start == -1) ? "" : s.substr(start, minLen);
    }
};