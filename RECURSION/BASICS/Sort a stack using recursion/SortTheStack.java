import java.util.Stack;

public class SortTheStack {
    
    private static Stack<Integer> stackSort(Stack<Integer> stk){
        if(stk.empty() || stk.size() == 1) return stk; // BASE CASE...
        else {
            int top = stk.pop();
            stackSort(stk); // RECURSIVE CALL...
            // SMALL WORK...
            insertElementsStack(top, stk); // ANOTHER RECURSIVE CALL...
            return stk;
        }
    }
    private static Stack<Integer> insertElementsStack(int el,Stack<Integer> stk){
        // METHOD TO INSERT ELEMENTS IN THE STACK ACCORDINGLY...
        if(stk.empty() || stk.peek() >= el){ // BASE CASE...
            stk.push(el);
            return stk;
        }
        else {
            int el2 = stk.pop();
            insertElementsStack(el,stk); // RECURSIVE CALL (ONLY IF REQUIRED)...
            stk.push(el2);
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
        // SORT STACK (IN DECREASING ORDER) RECURSIVELY PROBLEM-4:--------->
        System.out.println(stackSort(s));
    }
}
