import java.util.*;

public class OptimalApproach {

    private static void subSetsSum_1_OP(int idx, int sum, int[] arr, int n, List<Integer> ans) {
        if (idx == n) {
            ans.add(sum);
            return;
        }

        // first recursive call (taking the element)...
        subSetsSum_1_OP(idx + 1, sum + arr[idx], arr, n, ans);

        // Second recursive call (Not taking the element)...
        subSetsSum_1_OP(idx + 1, sum, arr, n, ans);
    }

    public static void main(String[] args) {
        int[] arr = {2, 2, 1, 3};
        Arrays.sort(arr);

        // Getting the sum of every subset of a array in list,Problem-14:--------->
        // OPTIMAL APPROACH...
        List<Integer> finalAns = new ArrayList<>();
        subSetsSum_1_OP(0, 0, arr, arr.length, finalAns);
        Collections.sort(finalAns); // to get answer in sorted way...
        System.out.println(finalAns);
    }
}
