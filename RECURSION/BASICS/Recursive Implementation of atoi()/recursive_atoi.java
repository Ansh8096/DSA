public class recursive_atoi {

    //Recursive Implementation of atoi() PROBLEM-1:------->
    private static int lengthOfValidString(String str){
        int n = str.length();
        int len = 0,i=0;
        while(i<n && Character.isDigit(str.charAt(i)))
        {
//            if(!Character.isDigit(str.charAt(i))) return -1;
            len++; i++;
        }
        if (len == 0) return -1; // no valid digits
        return (len);
    }

    private static int StringToInteger(String str,int last){
        // base call:
        if(last == 0){
            return str.charAt(last)-'0';
        }
        // recursive call:
        int ans =  StringToInteger(str,last-1);

        // small work:
        int ans2 = str.charAt(last) - '0';
        return ((ans*10) + ans2);
    }

    public static void main(String[] args) {

        String str = "  -042";
        int n = str.length(); int i = 0;

        // removing all the spaces from the front...
        while(i<n && (str.charAt(i)==' ')){
            i++;
        }

        // This is to store the sign...
        int sign = 1;
        if(str.charAt(i) == '-') {
            sign = -1;
            i++;
        }
        if(str.charAt(i) == '+') {
            sign = 1;
            i++;
        }

        // skip leading zeros
        while (i < n && str.charAt(i) == '0') {
            i++;
        }

        // Trimming the string...
        str = str.substring(i);

        // Getting the valid index...
        int last = lengthOfValidString(str);

        // If our string is starting from numbers then only proceed further , else return -1...
        if(last != -1){
            int ans = StringToInteger(str, last-1);
            int finalAns = sign * ans;

            System.out.println(finalAns);
        }
        else System.out.println(-1);
    }
}
