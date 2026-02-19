import java.util.*;

public class BruteForceApproach {

    private static void powerSetForArray(int[] arr, int n, List<Integer> finalAns) {
        List<List<Integer>> ans = new ArrayList<>();

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
            ans.add(temp);
        }

        // getting our final answer...
        // by storing the sum of every subset in the List...
        for (List<Integer> itr : ans) {
            int sum = 0;
            for (int itt : itr) {
                sum += itt;
            }
            finalAns.add(sum);
        }
    }
    private static List<Integer> subSetsSum_1_BR(int[] arr) {
        int n = arr.length;
        List<Integer> finalAns = new ArrayList<>(0); // we are initially starting are finalAnswer with 0...
        powerSetForArray(arr, n, finalAns);
        return finalAns;
    }

    public static void main(String[] args) {
        int [] arr = {2,2,1,3};
        Arrays.sort(arr);

        // Getting the sum of every subset of a array in list,Problem-14:--------->
        // BRUTE FORCE APPROACH...
        List<Integer> finalAns = subSetsSum_1_BR(arr);
        System.out.println(finalAns);
    }
}
