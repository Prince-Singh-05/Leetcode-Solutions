class Solution {
public:

    char largestFreq(unordered_map<char, int> freq) {

        char key = '/';
        int maxValue = INT_MIN;

        for(auto& pair : freq) {
            if(pair.second > maxValue) {
                key = pair.first;
                maxValue = pair.second;
            }
        }

        return key;
    }

    // string frequencySort(string s) {

    //     unordered_map<char, int> freq;

    //     for(char c : s) {
    //         freq[c]++;
    //     }

    //     string ans = "";

    //     for(int i = 0; i<s.size(); i++) {
    //         char c = largestFreq(freq);
            
    //         while(freq[c] > 0) {
    //             ans += c;
    //             freq[c]--;
    //         }
    //     }

    //     return ans;
        
    // }

    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count character frequencies
        for (char c : s) {
            freq[c]++;
        }

        // Create a min heap (priority queue) based on frequency
        priority_queue<pair<int, char>> pq;
        for (const auto& pair : freq) {
            pq.push({pair.second, pair.first});
        }

        // Build the sorted string
        string ans = "";
        while (!pq.empty()) {
            int count = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            while (count--) {
                ans += c;
            }
        }

        return ans;
    }
};