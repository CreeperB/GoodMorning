package ArithemeticOperation;

import java.util.*;

public class ArithemeticOperation {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int mode;
        double f, w, h, p;

        while (true) {
            System.out.println("Enter the mode of operation: ");
            System.out.println("1. Fahrenheit to Celsius");
            System.out.println("2. BMI Calculator");
            System.out.println("3. GPA Calculator");
            System.out.println("4. Exit");
            mode = sc.nextInt();
            switch (mode) {
                case 1:
                    System.out.printf("Enter Fahrenheit: ");
                    f = sc.nextDouble();
                    F_to_C(f);
                    break;
                case 2:
                    System.out.printf("Enter Weight(kg): ");
                    w = sc.nextDouble();
                    System.out.printf("Enter Height(cm): ");
                    h = sc.nextDouble() / 100;
                    BMI(w, h);
                    break;
                case 3:
                    System.out.printf("Enter Percentage: ");
                    p = sc.nextDouble();
                    GPA(p);
                    break;
                case 4:
                    System.out.println("Exiting...");
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        System.out.println(e);
                    }
                    sc.close();
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid mode");
                    break;
            }
            System.out.printf("\n");
        }
    }

    private static void F_to_C(double f) {
        double c = (f - 32) * 5 / 9;
        System.out.printf("Fahrenheit to Celsius: %6.2f\n", c);
    }

    private static void BMI(double w, double h) {
        double bmi = w / (h * h);
        System.out.printf("BMI: %4.1f\n", bmi);
    }

    private static void GPA(double p) {
        double gpa = (p / 100) * 4;
        System.out.printf("GPA: %4.2f\n", gpa);
    }
}
