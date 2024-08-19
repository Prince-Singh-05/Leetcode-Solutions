class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans, "", n, n);
        return ans;
    }

private:
    void helper(vector<string>& ans, string curr, int left, int right) {
        if(left < 0 || left > right) {
            return;
        }

        if(left == 0 && right == 0) {
            ans.push_back(curr);
        }

        helper(ans, curr + "(", left-1, right);
        helper(ans, curr + ")", left, right-1);
    }

};