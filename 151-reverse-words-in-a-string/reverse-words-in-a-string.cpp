class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;

        string currWord = "";

        for(int i = 0; i < s.size(); i++) {

            if(s[i] != ' ') {
                currWord += s[i];

                if(i == s.size()-1) {
                    words.push_back(currWord);
                }
            } else {

                if(currWord.size() >= 1) {
                    words.push_back(currWord);
                    currWord = "";
                }
            }
        }

        string ans = "";
        for(int i = words.size()-1; i >= 0; i--) {
            ans += words[i];

            if(i != 0) {
                ans += " ";
            }
        }

        cout << ans;

        return ans;
        
    }
};