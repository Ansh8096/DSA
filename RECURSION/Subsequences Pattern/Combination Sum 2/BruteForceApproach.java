import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;

public class BruteForceApproach {

    private static void combinationSum_2_BR(int idx, int arr[], int n, HashSet<List<Integer>> ans, List<Integer> temp, int target) {
        // Condition satisfied...
        // Slightly Optimization...
        if (target == 0) {
            List<Integer> copy = new ArrayList<>(temp);
            Collections.sort(copy); // sort only before adding to set...
            ans.add(copy);
            return;
        }

        // Condition satisfied...
        if (idx == n) {
            if (target == 0) {         // Condition satisfied...
                List<Integer> copy = new ArrayList<>(temp);
                Collections.sort(copy); // sort only before adding to set...
                ans.add(copy);
            }
            return;
        }

        // First recursive call :---->
        if (arr[idx] <= target) { // Condition satisfied...
            temp.add(arr[idx]);
            combinationSum_2_BR(idx + 1, arr, n, ans, temp, target - arr[idx]);
            temp.remove(temp.size() - 1);
        }

        // Second recursive call :---->
        combinationSum_2_BR(idx + 1, arr, n, ans, temp, target);
    }

    public static void main(String[] args) {
        // GENERATING ALL the combinations whose sum is k within a given array (repetition of elements is not allowed , all combinations must be unique also) PROBLEM-13:--------->
        List<Integer> temp = new ArrayList<>();
        int arr2[] = {10, 1, 2, 7, 6, 1, 5};
        int target2 = 8;
        HashSet<List<Integer>> ans2 = new HashSet<>();
        // BRUTE FORCE APPROACH...
        combinationSum_2_BR(0, arr2, arr2.length, ans2, temp, target2);
        System.out.println(ans2);
    }
}
