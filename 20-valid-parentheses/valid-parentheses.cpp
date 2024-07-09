class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        int n = s.length()-1;

        for(auto i:s)
        {
            if(i=='(' || i=='{' || i=='[') st.push(i);
            else {
                if(st.empty() || 
                    (st.top()=='(' and i!=')') || 
                    (st.top()=='{' and i!='}') || 
                    (st.top()=='[' and i!=']')) 
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};