class Solution {
private:
    bool checkValid(vector<int>& have, vector<int>& needed) {
        for (int i = 0; i<256; i++) {
            if (have[i] < needed[i]) return false;
        }

        return true;
    }

public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int low = 0;
        vector<int> have(256,0);
        vector<int> needed(256,0);
        int res_len = INT_MAX;
        int start = -1;

        if (m < n) return "";

        for (int i = 0; i < n; i++) {
            needed[t[i]]++;
        }

        for (int high = 0; high < m; high++) {
            have[s[high]]++;

            while (checkValid(have, needed)) {
                int len = high-low+1;

                if (res_len > len) {
                    res_len = len;
                    start = low;
                }

                have[s[low]]--;
                low++;
            }
        }

        return res_len == INT_MAX ? "" : s.substr(start, res_len);   
    }
};