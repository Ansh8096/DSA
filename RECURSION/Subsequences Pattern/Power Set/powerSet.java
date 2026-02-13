import java.util.ArrayList;
import java.util.List;

public class powerSet {

    private static List<String> powerSet(String s) {
        int n = s.length();
        List<String> ans = new ArrayList<>();
        // running loop from 0 to ((2^n) - 1)...
        for (int num = 0; num <= (1 << n) - 1; num++) {
            StringBuilder str = new StringBuilder();
            // for finding set bits in 'num'...
            for (int i = 0; i < n; i++) {
                // thw particular bit is set...
                if ((num & (1 << i)) != 0) {
                    // adding that particular index s[i] into String
                    str.append(s.charAt(i));
                }
            }
            // Adding every string into our answer...
            ans.add(new String(str));

        }
        return ans;
    }

    public static void main(String[] args) {
        // GENERATING ALL the subsequences for a String PROBLEM-8:--------->
        String s = "abc";
        List<String> ans = powerSet(s);
        System.out.println(ans);
    }
}
