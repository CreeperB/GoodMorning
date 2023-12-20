package matrix.util;

import java.lang.Math;

public class Matrix {
    int sizeX;
    int sizeY;
    int[][] matrix;

    public Matrix(int sizeY, int sizeX) {
        this.sizeX = sizeX;
        this.sizeY = sizeY;
        this.matrix = new int[sizeY][sizeX];
        for (int i = 0; i < sizeY; i++) {
            for (int j = 0; j < sizeX; j++) {
                this.matrix[i][j] = (int) (Math.random() * 101 - 50);
            }
        }
    }

    public Matrix(int sizeX, int sizeY, int[] arr) {
        this.sizeX = sizeX;
        this.sizeY = sizeY;
        this.matrix = new int[sizeY][sizeX];
        if (arr.length != sizeX * sizeY) {
            System.out.println("Array length must be equal to matrix size");
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            this.matrix[i / sizeX][i % sizeX] = arr[i];
        }
    }

    public void print() {
        for (int i = 0; i < sizeY; i++) {
            for (int j = 0; j < sizeX; j++) {
                System.out.printf("%6d ", this.matrix[i][j]);
            }
            System.out.println();
        }
        System.out.println("-----------------------------------------");
    }
}
