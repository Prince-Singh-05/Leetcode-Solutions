class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string ans;

        for(int i = 0; i<numRows; i++) {
            if(i == 0 || i == numRows-1) {
                int j = i;
                while(j < s.length()) {
                    ans += s[j];
                    j += (numRows-1)*2;
                }
            } else {
                int row = i;
                int j = i;
                int count = 0;
                while(j < s.length()) {
                    ans += s[j];
                    if(count % 2 == 0) {
                        j += 2*(numRows-1) - 2*row;
                    } else {
                        j += 2*(numRows-1) - (2*(numRows-1) - 2*row);
                    }
                    count++;
                }
            }
        }

        return ans;
    }
};