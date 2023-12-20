package MatrixInterfaceException;
import java.lang.Math;

public class Matrix {
    int rows;
    int cols;
    double[][] matrix;

    Matrix() {
        this.rows = 0;
        this.cols = 0;
        this.matrix = null;
    }

    Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        this.matrix = new double[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                this.matrix[i][j] = Math.random();
            }
        }
    }

    public void printMatrix() {
        if(this.matrix == null){
            return;
        }
        for(double[] row : this.matrix){
            for(double val : row){
                System.out.printf("%7.4f ", val);
            }
            System.out.println();
        }
        System.out.println("======================");
    }

    public void printMatrix(int n) {
        if(this.matrix == null){
            return;
        }
        for(double[] row : this.matrix){
            for(double val : row){
                System.out.printf("%7.4f ", val);
            }
            System.out.println();
        }
    }

    public Matrix addtion(Matrix B) throws MatrixException {
        if (this.rows != B.rows || this.cols != B.cols) {
            System.out.println(">>>> Catch matrix operation exceptions.");
            new MatrixException("Addition: mismatch matrix size.");
            return new Matrix();
        }
        Matrix C = new Matrix(this.rows, this.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                C.matrix[i][j] = this.matrix[i][j] + B.matrix[i][j];
            }
        }
        return C;
    }

    public Matrix subtract(Matrix B) throws MatrixException {
        if (this.rows != B.rows || this.cols != B.cols) {
            System.out.println(">>>> Catch matrix operation exceptions.");
            new MatrixException("Subtraction: mismatch matrix size.");
            return new Matrix();
        }
        Matrix C = new Matrix(this.rows, this.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                C.matrix[i][j] = this.matrix[i][j] - B.matrix[i][j];
            }
        }
        return C;
    }

    public Matrix multiply(Matrix other) throws MatrixException {
        if (this.cols != other.rows) {
            System.out.println(">>>> Catch matrix operation exceptions.");
            new MatrixException("Multiplication: mismatch matrix size.");
            return new Matrix();
        }
        Matrix result = new Matrix(this.rows, other.cols);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < this.cols; k++) {
                    result.matrix[i][j] += this.matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }

    public Matrix transpose() {
        Matrix result = new Matrix(this.cols, this.rows);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                result.matrix[j][i] = this.matrix[i][j];
            }
        }
        return result;
    }

    public Double innerProduct(Matrix other) throws MatrixException {
        if(this.rows != other.rows && this.cols != other.cols){
            System.out.println(">>>> Catch inner product both vector length mismatch exception.");
            new MatrixException("The two row and column vectors are not the same length.");
            return null;
        }
        else if (this.rows != other.rows) {
            System.out.println(">>>>  Catch inner product row vector length mismatch exception.");
            new MatrixException("The two column vectors are not the same length.");
            return null;
        }
        else if (this.cols != other.cols) {
            System.out.println(">>>>  Catch inner product column vector length mismatch exception.");
            new MatrixException("The two col vectors are not the same length.");
            return null;
        }
        double result = 0;
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                result += this.matrix[i][j] * other.matrix[i][j];
            }
        }
        return result;
    }

    public void printEachRow(String name) throws MatrixException {
        int i = 0;
        while (true) {
            System.out.printf("Row %d of %s: \n", i, name);
            VectorRow row = new VectorRow(this, i);
            Matrix vector = row.getVector();
            if (vector.matrix == null)
                break;
            else
                vector.printMatrix();
            i++;
        }
    }

    public void printEachCol(String name) throws MatrixException {
        int i = 0;
        while (true) {
            System.out.printf("Column %d of %s: \n", i, name);
            VectorCol col = new VectorCol(this, i);
            Matrix vector = col.getVector();
            if (vector.matrix == null)
                break;
            else
                vector.printMatrix();
            i++;
        }
    }

    Matrix getSubMatrix(int row, int col) {
        Matrix result = new Matrix(this.rows - 1, this.cols - 1);
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.cols; j++) {
                if (i < row && j < col)
                    result.matrix[i][j] = this.matrix[i][j];
                else if (i < row && j > col)
                    result.matrix[i][j - 1] = this.matrix[i][j];
                else if (i > row && j < col)
                    result.matrix[i - 1][j] = this.matrix[i][j];
                else if (i > row && j > col)
                    result.matrix[i - 1][j - 1] = this.matrix[i][j];
            }
        }
        return result;
    }

    public Double determinant(){
        if(this.rows != this.cols){
            System.out.println(">>>> Catch matrix operation exceptions.");
            new MatrixException("Determinant: Not a square matrix.");
            return null;
        }
        double res = 0;
        // get determinant of the matrix
        if(this.rows == 1){
            res = this.matrix[0][0];
        }else if(this.rows == 2){
            res = this.matrix[0][0] * this.matrix[1][1] - this.matrix[0][1] * this.matrix[1][0];
        }else{
            for(int i = 0; i < this.rows; i++){
                Matrix subMatrix = this.getSubMatrix(0, i);
                res += Math.pow(-1, i) * this.matrix[0][i] * subMatrix.determinant();
            }
        }
        return res;
    }
}