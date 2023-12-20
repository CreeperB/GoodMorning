package matrix;

import matrix.util.Matrix;
import matrix.util.Operator;

public class MatrixApp {
    public static void main(String[] args) throws Exception {
        Matrix A = new Matrix(5, 4);
        Matrix B = new Matrix(5, 4);
        Matrix C = new Matrix(5, 4);
        Matrix D = new Matrix(4, 6);
        Matrix E = new Matrix(5, 6);
        System.out.println("\n-----------------------------------------");
        System.out.println("Matrix A:");
        A.print();
        System.out.println("Matrix B:");
        B.print();
        System.out.println("Matrix C:");
        C.print();
        System.out.println("Matrix D:");
        D.print();
        System.out.println("Matrix E:");
        E.print();
        System.out.println("Resulting Matrix of A + B - C:");
        Operator op = new Operator();
        op.Subtract(op.Addition(A, B), C).print();
        System.out.println("Resulting Matrix of B × D + E:");
        op.Addition(op.Multiply(B, D), E).print();
        System.out.println("Resulting Matrix of E - A × D:");
        op.Subtract(E, op.Multiply(A, D)).print();

    }
}
