class Solution {
    public String removeDuplicates(String s) {
        
        // String ans = "";

        // for(int i = 0; i<s.length(); i++) {
        //     if(ans.isEmpty() || ans.charAt(ans.length()-1) != s.charAt(i)) {
        //         ans += s.charAt(i);
        //     } else {
        //         ans = ans.substring(0, ans.length()-1);
        //     }
        // }

        Stack<Character> st = new Stack<>();

        for(int i = 0; i<s.length(); i++) {
            if(st.isEmpty() || st.peek() != s.charAt(i)) {
                st.push(s.charAt(i));
            } else {
                st.pop();
            }
        }

        StringBuilder ans = new StringBuilder();

        for(char c : st) {
            ans.append(c);
        }

        return ans.toString();
    }
}