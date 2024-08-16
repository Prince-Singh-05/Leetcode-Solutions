class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        if(tokens.size() <= 2) {
            return stoi(tokens[0]);
        }
        
        stack<int> st;
        st.push(stoi(tokens[0]));
        st.push(stoi(tokens[1]));
        int i = 2, ans = 0;

        while(i < tokens.size()) {
            if((tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") && st.size() > 1) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int currResult = performOp(a, b, tokens[i]);
                st.push(currResult);
            }
            else {
                st.push(stoi(tokens[i]));
            }

            ++i;
        }


        return ans = st.top();
    }

private:

    int performOp(int a, int b, string op) {
        if(op == "+") {
            return a+b;
        }
        else if(op == "-") {
            return a-b;
        }
        else if(op == "*") {
            return a*b;
        }
        else {
            return a/b;
        }
    }

};