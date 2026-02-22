import java.util.*;

public class OptimalApproach {

    private static void subSets_2_OP(int idx, int n, int[] arr, List<List<Integer>> answer, List<Integer> temp) {
        // We need to store every unique subset that is generated during every function call...
        answer.add(new ArrayList<>(temp));

        for (int i = idx; i < n; i++) {
            // Skipping duplicates recursive calls...
            if (i > idx && arr[i] == arr[i - 1]) continue;
            temp.add(arr[i]);

            subSets_2_OP(i + 1, n, arr, answer, temp);
            temp.remove(temp.size() - 1);
        }
    }

    public static void main(String[] args) {
        int[] arr = {2, 2, 1, 3};
        Arrays.sort(arr);

        // Getting all the uniques subsets of array(which may or may not contain duplicates elements) into a list, Problem-15:--------->
        // OPTIMAL APPROACH...
        Arrays.sort(arr); // first we need to sort our given array...
        List<List<Integer>> answer = new ArrayList<>();
        subSets_2_OP(0, arr.length, arr, answer, new ArrayList<>());
        System.out.println(answer);

    }
}
