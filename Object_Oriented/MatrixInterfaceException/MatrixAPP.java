package MatrixInterfaceException;
public class MatrixAPP {
    public static void main(String[] args) throws MatrixException {
        Matrix A = new Matrix(6, 4);
        Matrix B = new Matrix(6, 4);
        Matrix C = new Matrix(4, 6);
        SMatrix S = new SMatrix(5);
        Double res;
        System.out.println("Matrix A:");
        A.printMatrix();
        System.out.println("Matrix B:");
        B.printMatrix();
        System.out.println("Matrix C:");
        C.printMatrix();
        System.out.println("Matrix A + B:");
        A.addtion(B).printMatrix();
        System.out.println("Matrix A - B:");
        A.subtract(B).printMatrix();
        System.out.println("Matrix A * C:");
        A.multiply(C).printMatrix();
        System.out.println("Matrix C * B:");
        C.multiply(B).printMatrix();
        System.out.println("Matrix (B - A) ^ T:");
        B.subtract(A).transpose().printMatrix();
        System.out.println("Matrix C - A:");
        C.subtract(A).printMatrix();

        A.printEachRow("A");
        A.printEachCol("A");

        System.out.println("Row A[0][*]:");
        VectorRow rA0 = new VectorRow(A, 0);
        rA0.getVector().printMatrix(1);
        System.out.println("Row B[0][*]:");
        VectorRow rB0 = new VectorRow(B, 0);
        rB0.getVector().printMatrix(1);
        res = rA0.getVector().innerProduct(rB0.getVector());
        if (res != null){
            System.out.printf("Inner product of A[0][*] and B[0][*]: %.4f\n", res);
            System.out.println("======================");
        }

        System.out.println("Column C[*][0]:");
        VectorCol cC0 = new VectorCol(C, 0);
        cC0.getVector().printMatrix(1);
        System.out.println("A[0][*] * C[*][0]:");
        rA0.getVector().multiply(cC0.getVector()).printMatrix();

        System.out.println("Row A[1][*]:");
        VectorRow rA1 = new VectorRow(A, 1);
        rA1.getVector().printMatrix(1);
        System.out.println("Row C[1][*]:");
        VectorRow rC1 = new VectorRow(C, 1);
        rC1.getVector().printMatrix(1);
        res = rA1.getVector().innerProduct(rC1.getVector());
        if (res != null){
            System.out.printf("Inner product of A[1][*] and C[1][*]: %.4f\n", res);
            System.out.println("======================");
        }
        System.out.println("Column A[*][0]:");
        VectorCol cA0 = new VectorCol(A, 0);
        cA0.getVector().printMatrix(1);
        System.out.println("Column B[*][0]:");
        VectorCol cB0 = new VectorCol(B, 0);
        cB0.getVector().printMatrix(1);
        res = cA0.getVector().innerProduct(cB0.getVector());
        if (res != null){
            System.out.printf("Inner product of A[*][0] and B[*][0]: %.4f\n", res);   
            System.out.println("======================");
        }
        System.out.println("Row C[0][*]:");
        VectorRow rC0 = new VectorRow(C, 0);
        rC0.getVector().printMatrix(1);
        System.out.println("A[*][0] * C[0][*]:");
        cA0.getVector().multiply(rC0.getVector()).printMatrix();

        System.out.println("Column A[*][1]:");
        VectorCol cA1 = new VectorCol(A, 1);
        cA1.getVector().printMatrix(1);
        System.out.println("Column C[*][1]:");
        VectorCol cC1 = new VectorCol(C, 1);
        cC1.getVector().printMatrix(1);
        res = cA1.getVector().innerProduct(cC1.getVector());
        if (res != null) {
            System.out.printf("Inner product of A[*][1] and C[*][1]: %.4f\n", res);
            System.out.println("======================");
        }

        System.out.println("Matrix S:");
        S.printMatrix(1);
        res = S.determinant();
        if (res != null) {
            System.out.println("The determinant of square matrix S: " + String.format("%6.3E", res));
            System.out.println("======================");
        }

        System.out.println("Matrix B * C:");
        B.multiply(C).printMatrix(1);
        res = B.multiply(C).determinant();
        if (res != null) {
            System.out.println("The determinant of square matrix B * C: " + String.format("%6.3E", res));
            System.out.println("======================");
        }

        System.out.println("Matrix A");
        A.printMatrix(1);
        res = A.determinant();
        if (res != null) {
            System.out.println("The determinant of square matrix A: " + String.format("%6.3E", res));
            System.out.println("======================");
        }
    }
}