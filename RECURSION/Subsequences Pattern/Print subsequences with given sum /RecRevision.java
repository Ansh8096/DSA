import java.util.ArrayList;
import java.util.List;

public class RecRevision {

    private static void printSubsequencesWithGivenSum(int idx, int[] arr, int n, List<Integer> list, int currentSum, int sum) {
        if (currentSum > sum) return;  // condition satisfied (slightly optimization) ...
        if (idx == n) {
            if (currentSum == sum) {
                System.out.println(list);
            }
            return;
        }

        // case1: taking the element...
        list.add(arr[idx]);
        currentSum += arr[idx];

        printSubsequencesWithGivenSum(idx + 1, arr, n, list, currentSum, sum);
        list.remove(list.size() - 1);
        currentSum -= arr[idx];
        // case2: Not taking the element...
        printSubsequencesWithGivenSum(idx + 1, arr, n, list, currentSum, sum);
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 1};
        int sum = 3;
        int n = arr.length;
        List<Integer> ans = new ArrayList<>();
        // GENERATING ALL the subsequences whose sum is k within a given array PROBLEM-9:--------->
        printSubsequencesWithGivenSum(0,arr,n,ans,0,sum);
    }
}
