class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int max_fruits = INT_MIN;
        unordered_map<int,int> freq;

        while (right < fruits.size()) {
            freq[fruits[right]]++;

            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }

            if (freq.size() <= 2) {
                max_fruits = max(max_fruits, right-left+1);
            }

            right++;
        }

        return max_fruits;
    }
};