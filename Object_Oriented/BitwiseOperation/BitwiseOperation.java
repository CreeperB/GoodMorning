package BitwiseOperation;

import java.util.*;

public class BitwiseOperation {
    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the first number: ");
        int a = sc.nextInt();
        System.out.println("Enter the second number: ");
        int b = sc.nextInt();
        System.out.println("Disjuction of a and b is: ");
        printBinary(a | b);
        System.out.println("Conjuction of a and b is: ");
        printBinary(a & b);
        System.out.println("Exclusive of a and b is: ");
        printBinary(a ^ b);
        System.out.println("Rightshift three bits of a is ");
        printBinary(a >> 3);
        System.out.println("Leftshift three bits of b is ");
        printBinary(b << 3);
        sc.close();
    }

    private static void printBinary(int a) {
        for (int i = 0; i < 32; i++) {
            System.out.print((a >> (31 - i)) & 1);
            if (i > 0 & (i + 1) % 4 == 0)
                System.out.print(" ");
        }
        System.out.println();
    }
}