
// package assignment;
/*
Assignment 03
*/
import java.util.Scanner;
import java.util.ArrayList;

public class A03_112502543 {
  static int count = 0;
  static int value = 0;
  static ArrayList<int[]> most_original_domain = new ArrayList<int[]>();
  static int address = 0;
  static int best_address = 0;
  static int temp = 0;
  static int temp_in_route = 0;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int array_size = scanner.nextInt();
    int array_number = scanner.nextInt();

    int[] hacker = new int[array_size];
    for (int i = 0; i < array_size; i++) {
      hacker[i] = scanner.nextInt();
    }
    for (int i = 0; i < array_number; i++) {
      int[] array = new int[array_size];
      for (int j = 0; j < array_size; j++) {
        array[j] = scanner.nextInt();
      }
      most_original_domain.add(array);
    }
    System.out.println("Enter the method (A or B): ");
    char method = scanner.next().charAt(0);
    scanner.close();
    ArrayList<int[]> original_domain = new ArrayList<int[]>();

    for (int i = 0; i < most_original_domain.size(); i++) {
      original_domain.add(most_original_domain.get(i));
    }

    if (method == 'A') {
      for (int i = 0; i < most_original_domain.size() + 1; i++) {
        int temp = hacking_data_A(original_domain, hacker);
        original_domain.clear();
        for (int z = 0; z < most_original_domain.size(); z++) {
          original_domain.add(most_original_domain.get(z));
        }
        if (temp > count) {
          count = temp;
          best_address = address;
        }
        address++;
      }
      most_original_domain.add(best_address, hacker);
      printDomain();

    } else {
      for (int i = 0; i < most_original_domain.size(); i++) {
        int temp = hacking_data_B(original_domain, hacker);
        original_domain.clear();
        for (int z = 0; z < most_original_domain.size(); z++) {
          original_domain.add(most_original_domain.get(z));
        }
        if (temp > value) {
          value = temp;
          best_address = address;
        }
        address++;
      }
      most_original_domain.add(best_address, hacker);
      printDomain();
    }
  }

  public static int hacking_data_A(ArrayList<int[]> original_domain, int[] hacker) {
    int count_temp = 0;
    int start = 0;
    original_domain.add(address, hacker);
    for (int k = 0; k < hacker.length; k++) {
      int temp = 0;
      if (hacker[k] == 0) {
        start = k;

        ArrayList<int[]> temp_domain = new ArrayList<int[]>();
        for (int i = 0; i < original_domain.size(); i++) {
          temp_domain.add(original_domain.get(i));
        }

        temp = routeA(temp_domain, address, start) - 1;
        temp_domain.clear();
        if (temp > count_temp) {
          count_temp = temp;
        }
      }
    }

    return count_temp;
  }

  public static int routeA(ArrayList<int[]> temp_domain, int i, int j) {
    // check if no way to go and using
    if (temp_domain.get(i)[j] == -1)
      return temp; // Return temp if index is out of bounds or already visited
    temp++;
    if(j+1 < temp_domain.get(0).length){
      if (temp_domain.get(i)[j + 1] != 0 || temp_domain.get(i)[j + 1] != -1)
        routeA(temp_domain, i, j + 1);
    }
    if(i+1 < temp_domain.size()){
      if (temp_domain.get(i + 1)[j] != 0 || temp_domain.get(i + 1)[j] != -1)
        routeA(temp_domain, i + 1, j);
    }
    if(j-1 >= 0){
      if (temp_domain.get(i)[j - 1] != 0 || temp_domain.get(i)[j - 1] != -1)
        routeA(temp_domain, i, j - 1);
    }
    if(i-1 >= 0){
      if (temp_domain.get(i - 1)[j] != 0 || temp_domain.get(i - 1)[j] != -1)
        routeA(temp_domain, i - 1, j);
    }
    return temp;
  }

  public static int routeB(ArrayList<int[]> temp_domain, int i, int j) {
    if (i < 0 || i > temp_domain.size() || j < 0 || j > temp_domain.get(0).length || temp_domain.get(i)[j] == -1)
      return temp; // Return temp if index is out of bounds or already visited
    temp += temp_domain.get(i)[j];
    temp_domain.get(i)[j] = -1;
    if (j + 1 < temp_domain.get(0).length && (temp_domain.get(i)[j + 1] != 0 || temp_domain.get(i)[j + 1] != -1))
      routeB(temp_domain, i, j + 1);
    if (i + 1 < temp_domain.size() && (temp_domain.get(i + 1)[j] != 0 || temp_domain.get(i + 1)[j] != -1))
      routeB(temp_domain, i + 1, j);
    if (j - 1 >= 0 && (temp_domain.get(i)[j - 1] != 0 || temp_domain.get(i)[j - 1] != -1))
      routeB(temp_domain, i, j - 1);
    if (i - 1 >= 0 && (temp_domain.get(i - 1)[j] != 0 || temp_domain.get(i - 1)[j] != -1))
      routeB(temp_domain, i - 1, j);
    return temp;
  }

  public static int hacking_data_B(ArrayList<int[]> original_domain, int[] hacker) {
    int value_temp = 0;
    int start = 0;
    original_domain.add(address, hacker);
    for (int k = 0; k < hacker.length; k++) {
      int temp = 0;
      if (hacker[k] == 0) {
        start = k;
        ArrayList<int[]> temp_domain = new ArrayList<int[]>();
        for (int i = 0; i < original_domain.size(); i++) {
          temp_domain.add(original_domain.get(i));
        }
        temp = routeB(temp_domain, address, start);
        temp_domain.clear();
        if (temp > value_temp) {
          value_temp = temp;
        }
      }

    }
    return value_temp;
  }

  public static void printDomain() {
    if (count != 0)
      System.out.println("At most " + count + " .");
    else
      System.out.println("At most " + value + " .");
    for (int i = 0; i < most_original_domain.size(); i++) {
      for (int j = 0; j < most_original_domain.get(i).length; j++) {
        System.out.print(most_original_domain.get(i)[j] + " ");
      }
      System.out.println();
    }

  }

}