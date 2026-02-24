import java.util.*;

public class RecRevision {

    private static boolean isPalindrome(int start, int end, String s) {
        while (start <= end) {
            if (s.charAt(start) != s.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    private static void gets_Partions(int idx, String s, List<String> temp, List<List<String>> ans) {
        // base case:-->
        if (idx == s.length()) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        // checking for every valid partition...
        for (int i = idx; i < s.length(); i++) {
            // doing partition only if we got a palindrome...
            if (isPalindrome(idx, i, s)) {
                temp.add(s.substring(idx, i + 1));
                gets_Partions(i + 1, s, temp, ans);
                temp.remove(temp.size() - 1);
            }
        }
    }

    private static List<List<String>> gettingPalindromePartions(String s) {
        List<String> temp = new ArrayList<>();
        List<List<String>> ans = new ArrayList<>();
        gets_Partions(0, s, temp, ans);
        return ans;
    }

    public static void main(String[] args) {
        // Getting all the palindrome partitions of String ,Problem-18:--------->
        String s = "aabb";
        List<List<String>> ans = gettingPalindromePartions(s);
        System.out.println(ans);

    }
}
