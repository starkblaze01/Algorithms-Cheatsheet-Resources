/*
 * Factorial of Large numbers in Java using BigInteger.
 * Input - Enter Test cases,Enter Number.
*/

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class factoflargenum {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0)
        {
            int n = sc.nextInt();
            BigInteger bg = BigInteger.ONE;
            for(int i=n;i>0;i--)
                bg = bg.multiply(BigInteger.valueOf(i));
            System.out.println(bg);
        }
    }
}