package Revision;

import java.util.*;

public class OptimalApproach {

    private static void combinationSum_2_OP(int idx, int arr[], int n, List<List<Integer>> ans, List<Integer> temp, int target) {

        // Condition satisfied...
        if (target == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }

        for (int i = idx; i < arr.length; i++) {

            // to prevent unnecessary recursive calls...
            if (i > idx && arr[i] == arr[i - 1]) continue;

            if (arr[i] > target) break; // slightly optimization...

            temp.add(arr[i]);
            combinationSum_2_OP(i + 1, arr, n, ans, temp, target - arr[i]);
            temp.remove(temp.size() - 1);
        }
    }

    public static void main(String[] args) {
        // GENERATING ALL the combinations whose sum is k within a given array (repetition of elements is not allowed , all combinations must be unique also) PROBLEM-13:--------->
        List<Integer> temp = new ArrayList<>();
        int arr2[] = {10, 1, 2, 7, 6, 1, 5};
        int target2 = 8;
        List<List<Integer>> ans = new ArrayList<>();
        // OPTIMAL APPROACH...
        Arrays.sort(arr2); // first we need to sort our array...
        combinationSum_2_OP(0, arr2, arr2.length, ans, temp, target2);
        System.out.println(ans);
    }
}
