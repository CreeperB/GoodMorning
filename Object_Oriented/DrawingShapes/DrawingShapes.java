package DrawingShapes;

import java.util.*;

public class DrawingShapes {

    public static void main(String[] args) {
        int len = 0;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the side of an isosceles triangle (between 3 and 29): ");
        len = sc.nextInt();
        triangle(len);
        System.out.print("Enter the side of a square (between 2 and 30): ");
        len = sc.nextInt();
        square(len);
        System.out.print("Enter the side of a rhombus (between 3 and 29): ");
        len = sc.nextInt();
        rhombus(len);
        sc.close();
    }

    static void triangle(int len) {
        System.out.println(" ".repeat(len - 1) + "*");
        for (int i = 0; i < len - 2; i++) {
            System.out.println(" ".repeat(len - i - 2) + "*" + " ".repeat(i * 2 + 1) + "*");
        }
        System.out.println("*".repeat(2 * len - 1));
    }

    static void square(int len) {
        System.out.println("*".repeat(len));
        for (int i = 0; i < len - 2; i++) {
            System.out.println("*" + " ".repeat(len - 2) + "*");
        }
        System.out.println("*".repeat(len));
    }

    static void rhombus(int len) {
        System.out.println(" ".repeat(len - 1) + "*");
        for (int i = 0; i < len - 2; i++) {
            System.out.println(" ".repeat(len - i - 2) + "*" + "@".repeat(i * 2 + 1) + "*");
        }
        for (int i = len - 1; i >= 1; i--) {
            System.out.println(" ".repeat(len - i - 1) + "*" + "@".repeat(i * 2 - 1) + "*");
        }
        System.out.println(" ".repeat(len - 1) + "*");
    }
}
