class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedWord = "";
        int l1 = word1.length();
        int l2 = word2.length();

        for(int i = 0; i < min(l1, l2); i++) {
            mergedWord += word1[i];
            mergedWord += word2[i];
        }

        if(l1 < l2) {
            mergedWord += word2.substr(l1);
        } else if (l2 < l1) {
            mergedWord += word1.substr(l2);
        }

        return mergedWord;
    }
};