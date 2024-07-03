class Solution {
public:
    int maxDepth(string s) {

        int maxi = 0;

        stack<char> st;

        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);

                int stackSize = st.size();
                
                if(maxi < stackSize) {
                    maxi = stackSize;
                }

            } else if(s[i] == ')') {
                st.pop();
            }
        }

        return maxi;
        
    }
};