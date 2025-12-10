class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int max_score = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());

        int l = 0;
        int r = tokens.size()-1;

        while (l <= r) {
            if (power >= tokens[l]) {
                score += 1;
                power -= tokens[l];
                l++;
                max_score = max(max_score, score);
            }
            else if (score > 0) {
                score -= 1;
                power += tokens[r];
                r--;
            } else {
                break;
            }
        }
           
        return max_score;
    }
};