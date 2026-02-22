import java.util.*;

public class BruteForceApproach {

    private static HashSet<List<Integer>> powerSetForArray2(int[] arr) {
        int n = arr.length;
        HashSet<List<Integer>> answer = new HashSet<>();

        // running loop from 0 to ((2^n) - 1)...
        for (int num = 0; num <= (1 << n) - 1; num++) {
            List<Integer> temp = new ArrayList<>();
            // for finding set bits in 'num'...
            for (int i = 0; i < n; i++) {
                // this particular bit is set...
                if ((num & (1 << i)) != 0) {
                    // adding that particular index arr[i] into List...
                    temp.add(arr[i]);
                }
            }
            // Adding every temp List into our answer...
            answer.add(temp);
        }
        return answer;
    }
    private static List<List<Integer>> subSets_2_BR(int[] arr) {
        HashSet<List<Integer>> answer = powerSetForArray2(arr);
        List<List<Integer>> finalAnswer = new ArrayList<>(answer);
        return finalAnswer;
    }

    public static void main(String[] args) {
        int[] arr = {2, 2, 1, 3};
        Arrays.sort(arr);

        // Getting all the uniques subsets of array(which may or may not contain duplicates elements) into a list, Problem-15:--------->
        // BRUTE FORCE APPROACH...
        List<List<Integer>> answer = subSets_2_BR(arr);
        System.out.println(answer);

    }
}
