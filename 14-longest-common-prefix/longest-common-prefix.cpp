class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.empty()) return "";

        string ans = strs[0];

        for(int i = 1; i<strs.size(); i++) {

            string word = strs[i];

            for(int j = 0; j<word.size(); j++) {

                if(word[j] != ans[j] && ans.size() >= j) {
                    ans = ans.substr(0, j);
                    break;
                }
            }

            if(word.size() < ans.size()) {
                ans = word;        
            }
        }

        return ans;

    }

};