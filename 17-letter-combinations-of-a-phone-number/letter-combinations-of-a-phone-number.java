import java.util.*;

class Solution {

    // public List<String> ans = new ArrayList<>();

    // public void giveComb(String digits, String arr[], int i, String comb) {
    //     if(i == digits.length()) {
    //         ans.add(comb);
    //         return;
    //     }

    //     char c = digits.charAt(i);
    //     String a = arr[c - '0'];
    //     for(char x1 : a.toCharArray()) {
    //         giveComb(digits, arr, i+1, comb+x1);
    //     }
    // }

    private List<String> giveComb(String digits, String[] arr) {
        if (digits.length() == 0) {
            List<String> bs = new ArrayList<>();
            bs.add("");
            return bs;
        }

        char c = digits.charAt(0);
        String a = arr[c - '0'];
        String smallinput = digits.substring(1);
        List<String> rest = giveComb(smallinput, arr);
        List<String> res = new ArrayList<>();
        for (String x : rest) {
            for (char x1 : a.toCharArray()) {
                res.add(x1 + x);
            }
        }
        return res;
    }

    public List<String> letterCombinations(String digits) {
        
        List<String> res = new ArrayList<String>();

        if(digits.length() == 0) {
            return res;
        }

        String arr[] = {"0", "0", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // giveComb(digits, arr, 0, "");
        res = giveComb(digits, arr);
        return res;
        
    }
}