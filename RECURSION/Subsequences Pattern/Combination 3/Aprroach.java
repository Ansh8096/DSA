import java.util.*;

public class Aprroach {

    private static void combinationSum_3(int idx, int arr[], int n, List<List<Integer>> ans, List<Integer> temp, int target, int k) {

        // Condition not satisfied...
        if (temp.size() > k) {
            return;
        }

        // Condition satisfied...
        if (temp.size() == k) {
            if (target == 0) {
                ans.add(new ArrayList<>(temp));
            }
            return;
        }

        for (int i = idx; i < arr.length; i++) {
            // to prevent unnecessary recursive calls...
            if (i > idx && arr[i] == arr[i - 1]) continue;

            if (arr[i] > target) break; // slightly optimization...

            temp.add(arr[i]);
            combinationSum_3(i + 1, arr, n, ans, temp, target - arr[i], k);
            temp.remove(temp.size() - 1);
        }
    }

    public static void main(String[] args) {
        // GENERATING ALL the combinations whose sum is n within a limited range(1-9), in which each combination has size k(repetition of elements is not allowed , all combinations must be unique also) PROBLEM-16:--------->
        int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        List<List<Integer>> ans3 = new ArrayList<>();
        int n = 7;
        int k = 3;
        combinationSum_3(0, arr3, arr3.length, ans3, new ArrayList<>(), n, k);
        System.out.println(ans3);a


    }
}
