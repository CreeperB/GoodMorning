package MatrixInterfaceException;
public class MatrixException extends Exception {
    public MatrixException(String message) {
        super(message);
        printStackTrace();
        System.out.println("******************************");
    }
}