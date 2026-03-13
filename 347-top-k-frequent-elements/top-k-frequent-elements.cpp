class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for (int n : nums) {
            freq[n]++;
        }

        for (const auto& pair : freq) {
            
            int num = pair.first;
            int fq = pair.second;

            pq.push({fq, num});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;

        while (!pq.empty()) {
            int elem = pq.top().second;
            res.push_back(elem);
            pq.pop();
        }

        return res;
    }
};