import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T > 0) {
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            if((a.multiply(a).subtract(b.multiply(b))).isProbablePrime(23))
                System.out.println("YES");
            else
                System.out.println("NO");
            
            T--;
        }
    }
}
