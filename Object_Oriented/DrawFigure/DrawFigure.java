package DrawFigure;

import java.util.*;

public class DrawFigure {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tiers, side, growth, width, height;
        System.out.println("Enter the number of tiers (2 to 5): ");
        tiers = sc.nextInt();
        System.out.println("Enter the side of top triangle (3 to 6): ");
        side = sc.nextInt();
        System.out.println("Enter the growth of two adjacent triangles (1 to 5): ");
        growth = sc.nextInt();
        System.out.println("Enter the width of the trunk (odd number, 3 to 9): ");
        width = sc.nextInt();
        System.out.println("Enter the height of the trunk (4 to 10): ");
        height = sc.nextInt();
        int start = side - 1 + (tiers - 1) * growth; // the mid of the last triangle
        draw_tree(start, tiers, side, growth); // draw the tree
        draw_trunk(start, width, height); // draw the trunk
        sc.close();
    }

    static void draw_tree(int start, int tiers, int side, int growth) {
        for (int i = 0; i < tiers; i++) {
            if (i == 0) { // draw the top triangle
                System.out.println(" ".repeat(start) + '#');
            }
            for (int j = 1; j < side - 1 + i * growth; j++) { // draw the two adjacent triangles
                System.out.println(" ".repeat(start - j) + "#" + "@".repeat(j * 2 - 1) + "#");
            }
            System.out.println(" ".repeat(start - side + 1 - i * growth) + "#".repeat(side * 2 - 1 + i * growth * 2)); // draw
                                                                                                                       // the
                                                                                                                       // bottom
                                                                                                                       // of
                                                                                                                       // the
                                                                                                                       // triangle
        }
    }

    static void draw_trunk(int start, int width, int height) {
        for (int i = 0; i < height; i++) { // draw the trunk
            System.out.println(" ".repeat(start - width / 2) + "|".repeat(width));
        }
    }
}