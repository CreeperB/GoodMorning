import java.util.ArrayList;
import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int array_size = scanner.nextInt();
        int array_number = scanner.nextInt();

        int[] hacker = new int[array_size];
        for (int i = 0; i < array_size; i++) {
            hacker[i] = scanner.nextInt();
        }

        ArrayList<int[]> most_original_domain = new ArrayList<>();

        for (int i = 0; i < array_number; i++) {
            int[] array = new int[array_size];
            for (int j = 0; j < array_size; j++) {
                array[j] = scanner.nextInt();
            }
            most_original_domain.add(array);
        }

        char method = scanner.next().charAt(0);
        scanner.close();

        // Depending on the method specified, call the respective function
        if (method == 'A') {
            int index = hacking_data_A(new ArrayList<>(most_original_domain), hacker);
            most_original_domain.add(index, hacker);
            // System.out.println("At most " + count + " count.");
            printDomain(most_original_domain);
        } else if (method == 'B') {
            int index = hacking_data_B(new ArrayList<>(most_original_domain), hacker);
            most_original_domain.add(index, hacker);
            // System.out.println("At most " + value + " value.");
            printDomain(most_original_domain);
        }
    }

    public static int hacking_data_A(ArrayList<int[]> original_domain, int[] hacker) {
        int maxCount = 0;
        int maxCountIndex = 0;
        for (int i = 0; i < original_domain.size(); i++) {
            // insert hacker[] at each position in original_domain
            ArrayList<int[]> temp_domain = new ArrayList<>(original_domain);
            temp_domain.add(i, hacker);
            for (int j = 0; j < hacker.length; j++) {
                if (hacker[j] == 0) {
                    int count = routeA(new ArrayList<>(temp_domain), i, j, true, 0);
                    System.out.println("Count: " + count + " at index: " + i + " " + j);
                    if (count > maxCount) {
                        maxCount = count;
                        maxCountIndex = i;
                    }
                }
            }
        }
        System.out.println("At most " + maxCount + " count.");
        System.out.println("Best address: " + maxCountIndex);
        return maxCountIndex;
    }

    public static int routeA(ArrayList<int[]> temp_domain, int i, int j, boolean enter, int currentCount) {
        // Base case: if the current cell is out of bounds or already visited (except
        // for the initial call)
        if (i < 0 || i >= temp_domain.size() || j < 0 || j >= temp_domain.get(0).length) {
            return currentCount;
        }
        if ((temp_domain.get(i)[j] == -1 || temp_domain.get(i)[j] == 0) && !enter) {
            return currentCount;
        }

        int temp = 1; // Counting the current cell as part of the route
        int original = temp_domain.get(i)[j]; // Storing the original value of the current cell

        // Mark the current cell as visited only if this is the initial call to routeA
        if (enter) {
            temp_domain.get(i)[j] = -1;
        }

        // Recursively explore adjacent cells
        temp += routeA(temp_domain, i, j + 1, false, currentCount); // Right
        temp += routeA(temp_domain, i + 1, j, false, currentCount); // Down
        temp += routeA(temp_domain, i, j - 1, false, currentCount); // Left
        temp += routeA(temp_domain, i - 1, j, false, currentCount); // Up

        // Restore the original value of the current cell
        temp_domain.get(i)[j] = original;

        // Return the maximum count encountered
        return Math.max(currentCount, temp);
    }

    public static int hacking_data_B(ArrayList<int[]> original_domain, int[] hacker) {
        int maxValue = 0;
        int maxValueIndex = 0;
        for (int i = 0; i < original_domain.size(); i++) {
            for (int j = 0; j < hacker.length; j++) {
                if (hacker[j] == 0) {
                    int value = routeB(new ArrayList<>(original_domain), i, j);
                    if (value > maxValue) {
                        maxValue = value;
                        maxValueIndex = i;
                    }
                }
            }
        }
        System.out.println("At most " + maxValue + " value.");
        return maxValueIndex;
    }

    public static int routeB(ArrayList<int[]> temp_domain, int i, int j) {
        if (i < 0 || i >= temp_domain.size() || j < 0 || j >= temp_domain.get(0).length || temp_domain.get(i)[j] == -1
                || temp_domain.get(i)[j] == 0) {
            return 0;
        }
        int temp = temp_domain.get(i)[j];
        temp_domain.get(i)[j] = -1; // Mark cell as visited
        temp += routeB(temp_domain, i, j + 1);
        temp += routeB(temp_domain, i + 1, j);
        temp += routeB(temp_domain, i, j - 1);
        temp += routeB(temp_domain, i - 1, j);
        return temp;
    }

    public static void printDomain(ArrayList<int[]> domain) {
        for (int i = 0; i < domain.size(); i++) {
            for (int j = 0; j < domain.get(i).length; j++) {
                System.out.print((domain.get(i)[j] == -1 ? 0 : domain.get(i)[j]) + " "); // Print 0 for visited cells
            }
            System.out.println();
        }
    }
}
