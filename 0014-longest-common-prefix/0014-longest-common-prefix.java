class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ans = "";

        Arrays.sort(strs);
        int n = strs.length;

        String first = strs[0], last = strs[n-1];

        for(int i = 0; i<Math.min(first.length(), last.length()); i++) {
            if(first.charAt(i) != last.charAt(i)) {
                return ans;
            }

            ans += first.charAt(i);
        }

        return ans;
    }
}