class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for(auto a: strs) {
            string word = a;
            sort(word.begin(), word.end());
            mp[word].push_back(a);
        }

        vector<vector<string>> ans;

        for(auto a: mp) {
            ans.push_back(a.second);
        }
        
        return ans;
    }
};