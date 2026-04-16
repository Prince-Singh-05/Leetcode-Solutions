class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> pq;

        for (char c: s) {
            map[c]++;
        }

        for (auto it: map) {
            int freq = it.second;
            char ch = it.first;

            pq.push({freq, ch});
        }

        int seat = 0;
        string res = "";

        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();

            if (seat == 0 || p.second != res[seat-1]) {
                res.push_back(p.second);
                p.first--;
                seat++;

                if (p.first > 0) {
                    pq.push(p);
                }
            } else {
                if (pq.empty()) {
                    return "";
                } else {
                    pair<int, char> p2 = pq.top();
                    pq.pop();

                    res.push_back(p2.second);
                    p2.first--;
                    seat++;

                    if (p2.first > 0) {
                        pq.push(p2);
                    }

                    pq.push(p);
                }
            }
        }

        return res;
    }
};