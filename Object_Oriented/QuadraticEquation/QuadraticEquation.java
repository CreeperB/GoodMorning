package QuadraticEquation;

import java.lang.Math.*;
import java.util.*;

class Root {
    double value;
    boolean ans;

    Root(double a, double b, double c, double r) {
        value = r;
        ans = a * r * r + b * r + c == 0;
    }
}

public class QuadraticEquation {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int mode;
        double a, b, c;
        while (true) {
            System.out.println("Enter the mode of operation: ");
            System.out.println("1. Check Quadratic Equation");
            System.out.println("2. Solve Quadratic Equation");
            System.out.println("3. Exit");
            mode = sc.nextInt();
            if (mode == 3) {
                return;
            }
            System.out.print("Enter coefficient a: ");
            a = sc.nextDouble();
            System.out.print("Enter coefficient b: ");
            b = sc.nextDouble();
            System.out.print("Enter coefficient c: ");
            c = sc.nextDouble();
            switch (mode) {
                case 1:
                    System.out.print("Enter the first root r1: ");
                    Root r1 = new Root(a, b, c, sc.nextDouble());
                    System.out.print("Enter the second root r2: ");
                    Root r2 = new Root(a, b, c, sc.nextDouble());
                    if (r1.ans && r2.ans) {
                        System.out.printf("%f and %f are root of %fX**2 + %fX + %f\n", r1.value, r2.value, a, b, c);
                    } else if (r1.ans) {
                        System.out.printf("%f is the root of %fX**2 + %fX + %f but %f isn't\n", r1.value, a, b, c,
                                r2.value);
                    } else if (r2.ans) {
                        System.out.printf("%f is the root of %fX**2 + %fX + %f but %f isn't\n", r2.value, a, b, c,
                                r1.value);
                    } else {
                        System.out.printf("None of it is root of %fX**2 + %fX + %f\n", a, b, c);
                    }
                    break;
                case 2:
                    double def = b * b - 4 * a * c;
                    double r = -1 * b / (2 * a); // without def
                    if (def > 0) {
                        System.out.printf("The real roots of %fX**2 + %fX + %f are %f and %f\n", a, b, c,
                                (-b + Math.sqrt(def)) / (2 * a), (-b - Math.sqrt(def)) / (2 * a));
                    } else if (def == 0) {
                        System.out.printf("The multiple real root of %fX**2 + %fX + %f is %f\n", a, b, c, r);
                    } else {
                        double i = Math.sqrt(-def) / (2 * a);
                        System.out.printf("The complex roots of %fX**2 + %fX + %f are %f+%fi and %f-%fi\n", a, b, c, r,
                                i, r, i);
                    }
                default:
                    break;
            }
        }
    }
}