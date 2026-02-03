class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        int i = 0;        

        while (i < s.size()) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                brackets.push(s[i]);
                i++;
                continue;
            }

            if (brackets.empty()) {
                return false;
            }
            
            if (brackets.top() == '(') {
                if (s[i] == ')')
                    brackets.pop();
                else return false;
            }
            else if (brackets.top() == '{') {
                if (s[i] == '}')
                    brackets.pop();
                else return false;
            }
            else if (brackets.top() == '[') {
                if (s[i] == ']')
                    brackets.pop();
                else return false;
            }
            i++;
        }

        return brackets.empty();
    }
};