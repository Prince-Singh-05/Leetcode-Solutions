import java.util.*;

class Solution {

    public List<String> ans = new ArrayList<>();

    public void giveComb(String digits, String arr[], int i, String comb) {
        if(i == digits.length()) {
            ans.add(comb);
            return;
        }

        char c = digits.charAt(i);
        String a = arr[c - '0'];
        for(char x1 : a.toCharArray()) {
            giveComb(digits, arr, i+1, comb+x1);
        }
    }

    public List<String> letterCombinations(String digits) {
        
        List<String> res = new ArrayList<String>();

        if(digits.length() == 0) {
            return res;
        }

        String arr[] = {"0", "0", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        giveComb(digits, arr, 0, "");
        return ans;
        
    }
}