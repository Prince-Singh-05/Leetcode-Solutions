class Solution {
    public String removeDuplicates(String s) {
        String ans = "";

        for(int i = 0; i<s.length(); i++) {
            if(ans.isEmpty() || ans.charAt(ans.length()-1) != s.charAt(i)) {
                ans += s.charAt(i);
            } else {
                ans = ans.substring(0, ans.length()-1);
            }
        }

        return ans;
    }
}