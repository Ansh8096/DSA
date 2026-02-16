import java.util.ArrayList;
import java.util.List;

public class RecRevision {

    private static int countAllSubsequencesWithGivenSum(int idx, int[] arr, int n, int currentSum, int sum) {
        if (currentSum > sum) return 0;  // condition not satisfied (slightly optimization)...
        // condition satisfied...
        if (idx == n) {
            // condition satisfied...
            if (currentSum == sum) return 1;
            return 0;
        }

        // case1: taking the element...
        currentSum += arr[idx];
        int l = countAllSubsequencesWithGivenSum(idx + 1, arr, n, currentSum, sum);
        currentSum -= arr[idx];

        // case2: Not taking the element...
        int r = countAllSubsequencesWithGivenSum(idx + 1, arr, n, currentSum, sum);
        return l + r;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 1};
        int sum = 4;
        int n = arr.length;
        List<Integer> ans = new ArrayList<>();
        // Counting all the subsequences whose sum is k within a given array  PROBLEM-11:--------->
        System.out.println(countAllSubsequencesWithGivenSum(0, arr, n, 0, sum));
    }
}
