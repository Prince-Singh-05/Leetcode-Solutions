class MyComparator {
public:
    bool operator()(pair<int, string> a, pair<int, string> b) const {
        if (a.first < b.first) return true;
        else if (a.first == b.first && a.second > b.second) return true;
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        using pis = pair<int, string>;
        priority_queue<pis, vector<pis>, MyComparator> pq;

        for (string w : words) {
            freq[w]++;
        }

        for (const auto& pair : freq) {
            string word = pair.first;
            int fq = pair.second;

            pq.push({fq, word});
        }

        vector<string> res;

        while (k--) {
            string word = pq.top().second;
            res.push_back(word);
            pq.pop();
        }

        return res;
    }
};