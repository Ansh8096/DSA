import java.util.ArrayList;
import java.util.List;

public class RecRevision {

    private static boolean printAnyOneSubsequencesOfGivenSum(int idx, int[] arr, int n, List<Integer> list, int currentSum, int sum) {
        if (currentSum > sum) return false; // condition not satisfied (slightly optimization)...
        // condition satisfied...
        if (idx == n) {
            // condition satisfied...
            if (currentSum == sum) {
                System.out.println(list);
                return true;
            }
            return false;
        }

        // case1: taking the element...
        list.add(arr[idx]);
        currentSum += arr[idx];

        if (printAnyOneSubsequencesOfGivenSum(idx + 1, arr, n, list, currentSum, sum) == true) {
            return true; // this will avoid calling any recursive call further...
        }
        list.remove(list.size() - 1);
        currentSum -= arr[idx];

        // case2: Not taking the element...
        if (printAnyOneSubsequencesOfGivenSum(idx + 1, arr, n, list, currentSum, sum) == true) {
            return true; // this will avoid calling any recursive call further...
        }
        return false;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 1};
        int sum = 3;
        int n = arr.length;
        List<Integer> ans = new ArrayList<>();
        // GENERATING ONLY ONE the subsequences whose sum is k within a given array PROBLEM-10:--------->
        printAnyOneSubsequencesOfGivenSum(0,arr,n,ans,0,sum);
    }
}
