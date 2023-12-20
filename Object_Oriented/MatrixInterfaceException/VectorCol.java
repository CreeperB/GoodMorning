package MatrixInterfaceException;
public class VectorCol extends Matrix {
    Matrix mat;
    int col;
    VectorCol(Matrix mat, int col) {
        this.mat = mat;
        this.col = col;
    }
    public Matrix getVector(){
        if(this.col >= mat.cols){
            System.out.println(">>>> Catch col vector exception.");
            new MatrixException("Column " + this.col + " does not exist.");
            return new Matrix();
        }
        Matrix result = new Matrix(mat.rows, 1);
        for(int i = 0; i < mat.rows; i++) {
            result.matrix[i][0] = mat.matrix[i][this.col];
        }
        return result;
    }
}
