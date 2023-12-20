package MatrixInterfaceException;
public class VectorRow extends Matrix {
    Matrix mat;
    int row;
    VectorRow(Matrix mat, int row) {
        this.mat = mat;
        this.row = row;
    }
    public Matrix getVector() {
        if(this.row >= mat.rows){
            System.out.println(">>>> Catch row vector exception.");
            new MatrixException("Row " + this.row + " does not exist.");
            return new Matrix();
        }
        Matrix result = new Matrix(1, mat.cols);
        for(int i = 0; i < mat.cols; i++) {
            result.matrix[0][i] = mat.matrix[this.row][i];
        }
        return result;
    }
}
