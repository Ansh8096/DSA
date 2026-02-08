import java.util.ArrayList;
import java.util.List;

public class generateValidParenthesis {

    // FOR PRINTING
    private static void printingList(List<String> lt){
        for (String str : lt){
            System.out.print(str + " ");
        }
    }

    // PROBLEM-7:------>
    private static void  backTracking(int n, int openingN, int closingN, StringBuilder str, List<String> ans){
        // Base case...
        if(openingN == n && closingN == n){
            ans.add(str.toString()); // toString: converts the StringBuilder object back into an immutable String object...
            return;
        }

        // adding '(' in the str , only if it matches the condition...
        if(openingN < n){
            str.append('(');
            backTracking(n,openingN+1,closingN,str,ans);
            str.deleteCharAt(str.length()-1); // helps in backtracking...
        }

        // adding ')' , only if it matches the condition...
        if(closingN < openingN){
            str.append(')');
            backTracking(n,openingN,closingN+1,str,ans);
            str.deleteCharAt(str.length()-1); // helps in backtracking...
        }

    }
    private static List<String> generatingParenthesis(int n){
        List<String> ans = new ArrayList<>();
        // String builder helps us to manipulate string efficiently, and allow us to perform append,deletion etc on string...
        StringBuilder str = new StringBuilder();
        backTracking(n,0,0,str,ans);
        return ans;
    }

    public static void main(String[] args) {
        int n = 3;
        // GENERATING ALL VALID PARENTHESIS COMBINATIONS STRINGS FOR INPUT N PROBLEM-7:--------->
        List<String> ans = generatingParenthesis(n);
        printingList(ans);

    }
}
