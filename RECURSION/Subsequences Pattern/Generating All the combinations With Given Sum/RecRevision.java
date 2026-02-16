import java.util.ArrayList;
import java.util.List;

public class RecRevision {

    // PROBLEM-12:------>
    private static void combinationSum_1(int idx, int arr[], int n, List<List<Integer>> ans,List<Integer> temp,int target){
        // Condition satisfied...
        // Slightly Optimization...
        if(target == 0){
            ans.add(new ArrayList<>(temp));
            return;
        }
        // Condition satisfied...
        if(idx == n) {
            if(target == 0){         // Condition satisfied...
//                ans.add(temp); // we can't do this , because it will only add the reference of the temp...
                ans.add(new ArrayList<>(temp)); // Instead we should make the copy of temp...
            }
            return;
        }

        // First recursive call :---->
        if(arr[idx] <= target){ // Condition satisfied...
            temp.add(arr[idx]);
            combinationSum_1(idx,arr,n,ans,temp,target - arr[idx]);
            temp.remove(temp.size()-1);
        }

        // Second recursive call :---->
        combinationSum_1(idx+1,arr,n,ans,temp,target);
    }

    public static void main(String[] args) {
        int arr[] = {2,3,6,7};
        int target = 7;
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        // GENERATING ALL the combinations whose sum is k within a given array(repetition of elements is allowed) PROBLEM-12:--------->
        combinationSum_1(0,arr,arr.length,ans,temp,target);
        System.out.println(ans);
    }
}
