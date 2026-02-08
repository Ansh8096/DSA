public class OptimalApproach {

    private static long mod = 1_000_000_007;
    private static long myPow_OP(long x, long n) {
        long ans = 1;
        long n1 = n; // taking copy of n...

        while(n1>0){
            if(n1 % 2 == 0){
                x = (x*x) % mod; // using mod to ensure it doesn't exceed int...
                n1 = n1/2;
            }
            else{
                ans = (ans*x) % mod; // using mod to ensure it doesn't exceed int...
                n1 = n1 - 1;
            }
        }
        return ans;
    }
    private static int countGoodNumbers(long n){
        long evenPlaces = (n+1) / 2;
        long oddPlaces = n/2;
        long pow5 = (myPow_OP(5, evenPlaces));
        long pow4 = (myPow_OP(4, oddPlaces));
        return (int)((pow5 * pow4)% mod);
    }

    public static void main(String[] args) {
        long n = 50;
        System.out.println(countGoodNumbers(n));
    }
}
