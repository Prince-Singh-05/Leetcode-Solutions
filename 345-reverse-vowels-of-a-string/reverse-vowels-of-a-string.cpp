class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        string ans = "";

        char vowel[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'}; 

        for(char ch: s) {
            bool isVowel = find(begin(vowel), end(vowel), ch) != end(vowel);
            if(isVowel) {
                vowels.push_back(ch);
            }
        }

        int j = vowels.size()-1;

        for(int i = 0; i<s.size(); i++) {
            bool isVowel = find(begin(vowel), end(vowel), s[i]) != end(vowel);
            if(isVowel) {
                ans += vowels[j--];
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};