class Solution {
public:
    int numberOfSubstrings(string s) {
        
        // Brute Force => T.C = O(N^2) && S.C = O(1)
        // int count = 0;
        // for(int i = 0; i<s.size(); i++) {
        //     unordered_map<int, int> freq;

        //     for(int j = i; j<s.size(); j++) {
        //         freq[s[j] - 'a']++;

        //         if((freq[0] + freq[1] + freq[2] >= 3) && (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)) {
        //             count++;
        //         }
        //     }
        // }

        // return count;

        // Better => T.C = O(N^2) && S.C = O(1)  || slightly optimized from above approach
        // int count = 0;

        // for(int i = 0; i<s.size(); i++) {
        //     unordered_map<int,int> freq;

        //     for(int j = i; j<s.size(); j++) {
        //         freq[s[j] - 'a']++;

        //         if((freq[0] + freq[1] + freq[2] >= 3) && (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)) {
        //             count = count + (s.size()-j);
        //             break;
        //         }
        //     }
        // }

        // return count;

        // Optimal Approach => T.C = O(N) && S.C = O(1)
        int lastSeen[3] = {-1, -1, -1};
        int count = 0;

        for(int i = 0; i<s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count = count + min(lastSeen[0], min(lastSeen[1], lastSeen[2])) + 1;
            }
        }

        return count;
    }
};