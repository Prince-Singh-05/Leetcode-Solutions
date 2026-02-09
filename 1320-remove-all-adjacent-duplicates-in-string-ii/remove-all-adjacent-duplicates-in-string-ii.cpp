class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k) return s;
        
        stack<char> st;
        stack<int> count;

        for(int i=0; i<n; ++i){
            if (!st.empty() && st.top() == s[i]) {
                count.push(count.top() + 1);
            } else {
                count.push(1);
            }

            st.push(s[i]);

            if (count.top() == k) {
                for (int j = 0; j<k; j++) {
                    st.pop();
                    count.pop();
                }
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};