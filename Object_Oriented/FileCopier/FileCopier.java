import java.io.*;
import java.util.Scanner;

public class FileCopier {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("<<<< Copy ");
        String sourceFile = sc.next();
        String targetFile = sc.next();
        try {
            if ((new File(targetFile)).exists()) {
                System.out.printf("The %s already exist\n", targetFile);
                sc.close();
                return;
            }
            FileInputStream inputFile = new FileInputStream(sourceFile);
            FileOutputStream outputFile = new FileOutputStream(targetFile);
            int n = inputFile.available();
            int i;
            while ((i = inputFile.read()) != -1) {
                outputFile.write((char) i);
            }
            System.out.printf("The FileCopier is copied %d bytes successfully\n", n);
            inputFile.close();
            outputFile.close();
        } catch (Exception e) {
            System.out.printf("The %s does not exist\n", sourceFile);
        }

        sc.close();
    }
}