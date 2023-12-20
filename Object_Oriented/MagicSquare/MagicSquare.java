package MagicSquare;

import java.util.Scanner;

public class MagicSquare {
    static void Create(int[][] square, int size, int pos, int step) {
        int[][] STEP = { { -1, -1 }, { 1, -1 }, { 1, 1 }, { -1, 1 } };
        int[][] POS = { { (size - 1) / 2, 0 }, { size - 1, (size - 1) / 2 }, { (size - 1) / 2, size - 1 },
                { 0, (size - 1) / 2 } };
        int posX = POS[pos][0], posY = POS[pos][1];
        int stepX = STEP[step][0], stepY = STEP[step][1];
        for (int i = 1; i <= size * size; i++) {
            square[posY][posX] = i;
            posX += stepX;
            posY += stepY;
            if (posX < 0) {
                posX = size - 1;
            } else if (posX >= size) {
                posX = 0;
            }
            if (posY < 0) {
                posY = size - 1;
            } else if (posY >= size) {
                posY = 0;
            }
            int flag = 0;
            while (square[posY][posX] != 0 && i != size * size) {
                if (flag == 0) {
                    posX -= stepX;
                    if (posX < 0) {
                        posX = size - 1;
                    } else if (posX >= size) {
                        posX = 0;
                    }
                    flag = 1;
                }
                posY += 1;
                if (posY >= size) {
                    posY = 0;
                }
            }
        }
    }

    static int Check(int[][] square, int size) {
        int base = 0, sum = 0;
        for (int i = 0; i < size; i++)
            base += square[i][i];
        for (int i = 0; i < size; i++)
            sum += square[size - i - 1][i];
        if (sum != base)
            return -1;
        for (int i = 0; i < size; i++) {
            sum = 0;
            for (int j = 0; j < size; j++)
                sum += square[i][j];
            if (sum != base)
                return -1;
        }
        return base;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size, pos, step;
        System.out.print("Enter the size of the magic square (3‹=n<20, odd integer): ");
        size = sc.nextInt();
        int[][] square = new int[size][size];
        System.out.println("Enter position of the starting cell at the center of");
        System.out.print("0: top row, 1: right-most column, 2: bottom row, 3: left-most column: ");
        pos = sc.nextInt();
        System.out.print("Set move step (0: upper-left, 1: upper-right, 2: lower-right, 3: lower-left): ");
        step = sc.nextInt();
        Create(square, size, pos, step);
        System.out.printf("The magic square of degree %d:\n", size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                System.out.printf("%4d", square[i][j]);
            System.out.println();
        }
        int sum = 0;
        sum = Check(square, size);
        if (sum == -1)
            System.out.println("The magic square failed verification.");
        else {
            System.out.println("The magic square passed verification.");
            System.out.printf("The sum of each row, column and diagonal is %d.\n", sum);
        }
        sc.close();
    }
}