import java.util.Stack;

public class RecRevision {

    private static Stack<Integer> reverseStack(Stack<Integer> stk) {
        if (stk.empty() || stk.size() == 1) return stk; // BASE CASE...
        else {
            int top = stk.pop();
            reverseStack(stk); // RECURSIVE CALL...
            // SMALL WORK...
            return insertion(top, stk); // ANOTHER RECURSIVE CALL...
        }
    }

    private static Stack<Integer> insertion(int top, Stack<Integer> stk) {
        if (stk.empty() || stk.size() == 1) { // BASE CASE...
            int top2 = stk.pop();
            stk.push(top);
            stk.push(top2);
            return stk;
        } else {
            int topTemp = stk.pop();
            insertion(top, stk);
            stk.push(topTemp);
            return stk;
        }
    }

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(11);
        s.push(2);
        s.push(32);
        s.push(3);
        s.push(41);

        System.out.println(s);
        // REVERSE STACK RECURSIVELY PROBLEM-5:------------>
        System.out.println(reverseStack(s));
    }
}
