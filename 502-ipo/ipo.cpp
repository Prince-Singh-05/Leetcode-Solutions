class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> proj;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            proj.push_back({capital[i], profits[i]});
        }

        sort(proj.begin(), proj.end());
        int s = 0;

        while (k--) {
            while (s < n) {
                if (proj[s].first > w) break;
                pq.push(proj[s].second);
                s++;
            }

            if (pq.empty()) return w;

            w = w + pq.top();
            pq.pop();
        }

        return w;
    }
};