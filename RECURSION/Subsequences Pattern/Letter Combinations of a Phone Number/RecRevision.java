import java.util.*;

public class RecRevision {

    private static void helperFunc(String num, String currStr, List<String> ans, String[] hashArr) {
        // base case:--->
        if (num.isEmpty()) {
            if (!currStr.isEmpty()) {
                ans.add(new String(currStr));
            }
            return;
        }

        // to get the last digit of n in (int)...
        int n1 = num.charAt(num.length() - 1) - '0'; // e.g:- '3' -> 3
        // to get the String corresponding to index n1 present in the hashArr...
        String s1 = hashArr[n1];

        // to get all the combinations of every char in this string with the rest of the strings chars...
        for (int i = 0; i < s1.length(); i++) {
            helperFunc(num.substring(0, num.length() - 1), s1.charAt(i) + "" + currStr, ans, hashArr);
        }
    }

    private static List<String> letterCombinationsOfPhoneNumber_OP(String num) {
        List<String> ans = new ArrayList<>();
        String[] hashArr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        helperFunc(num, new String(), ans, hashArr);
        return ans;
    }

    public static void main(String[] args) {

        List<String> ans = letterCombinationsOfPhoneNumber_OP("4232");
        System.out.println(ans);
        
    }
}
