package complexNumber;

import complexNumber.util.Complex;
import complexNumber.util.Operator;

import java.util.Scanner;
import java.text.DecimalFormat;

public class ComplexNumber {
    public static void main(String[] args) {
        double rel_a, img_a, rel_b, img_b;
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.####");
        System.out.print("Enter the first complex number a + bi = ");
        rel_a = sc.nextDouble();
        img_a = sc.nextDouble();
        System.out.print("Enter the second complex number c + di = ");
        rel_b = sc.nextDouble();
        img_b = sc.nextDouble();
        sc.close();
        System.out.printf("The complex numbers are: a = %s+%si and b = %s+%si\n", df.format(rel_a),
                df.format(img_a), df.format(rel_b),
                df.format(img_b));
        Complex a = new Complex(rel_a, img_a);
        Complex b = new Complex(rel_b, img_b);
        System.out.println("After complex number arithmetic operations:");
        System.out.println("=============================================");
        Operator op = new Operator();
        System.out.print("Complex addition: ");
        op.addition(a, b).printComplex();
        System.out.print("Complex substraction: ");
        op.substraction(a, b).printComplex();
        System.out.print("Complex multiplication: ");
        op.multiplication(a, b).printComplex();
        System.out.print("Complex division: ");
        op.division(a, b).printComplex();
        System.out.print("Complex absolute: ");
        op.absolute(a).printComplex();
    }
}