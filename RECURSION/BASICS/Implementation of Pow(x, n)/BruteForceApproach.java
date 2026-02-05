public class BruteForceApproach {

    private static double implenting_pow_BR(double x,int n){
        long n1 = 0;
        if(n<0){
            n1 = -1*n;
        }
        else n1 = n;

        double ans = 1.0;

        for(int i = 1;i<=n1;i++){
            ans *= x;
        }

        // If n is -ve:
        if(n<0) return (double) 1 / ans;
            // Else n was +ve:
        else return ans;
    }

    public static void main(String[] args) {
      double x = 2.00000;
      int n = 10;
      System.out.println(implenting_pow_BR(x,n));

    }
}
