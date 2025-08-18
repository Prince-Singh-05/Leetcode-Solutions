class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowelSet = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        int left = 0, right = s.size()-1;

        while(left < right) {
            while(left < right && vowelSet.find(s[left]) == vowelSet.end()) left++;
            while(left < right && vowelSet.find(s[right]) == vowelSet.end()) right--;

            if(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};