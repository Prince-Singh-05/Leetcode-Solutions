class Solution {
    public String removeDuplicates(String s, int k) {

        Stack<Character> st = new Stack<>();
        Stack<Integer> count = new Stack<>();

        for(int i = 0; i<s.length(); i++) {
            
            if(!st.isEmpty() && st.peek() == s.charAt(i)) {
                count.push(count.peek() + 1);
            } else {
                count.push(1);
            }

            st.push(s.charAt(i));

            if(count.peek() == k) {
                for(int j = 0; j<k; j++) {
                    st.pop();
                    count.pop();
                }
            }
        }

        StringBuilder ans = new StringBuilder();
        for(char c : st) {
            ans.append(c);
        }

        return ans.toString();
        
    }
}