package matrix.util;

public class Operator {
    public Matrix Addition(Matrix A, Matrix B) {
        Matrix C = new Matrix(A.sizeY, A.sizeX);
        for (int i = 0; i < A.sizeY; i++) {
            for (int j = 0; j < A.sizeX; j++) {
                C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
            }
        }
        return C;
    }

    public Matrix Subtract(Matrix A, Matrix B) {
        Matrix C = new Matrix(A.sizeY, A.sizeX);
        for (int i = 0; i < A.sizeY; i++) {
            for (int j = 0; j < A.sizeX; j++) {
                C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
            }
        }
        return C;
    }

    public Matrix Multiply(Matrix A, Matrix B) {
        Matrix C = new Matrix(A.sizeY, B.sizeX);
        int len = A.sizeX;
        for (int i = 0; i < A.sizeY; i++) {
            for (int j = 0; j < B.sizeX; j++) {
                int tmp = 0;
                for (int k = 0; k < len; k++) {
                    tmp += A.matrix[i][k] * B.matrix[k][j];
                }
                C.matrix[i][j] = tmp;
            }
        }
        return C;
    }
}
