class Solution {

    public int expand(String s, int i, int j) {

        int count = 0;

        while(i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            count++;
            i--;
            j++;
        }

        return count;
    }

    public int countSubstrings(String s) {
        int totalCount = 0;

        for(int i = 0; i<s.length(); i++) {

            // ODD
            int oddAns = expand(s, i, i); 

            // EVEN
            int evenAns = expand(s, i, i+1);

            totalCount = totalCount + oddAns + evenAns;
        }

        return totalCount;
    }
}