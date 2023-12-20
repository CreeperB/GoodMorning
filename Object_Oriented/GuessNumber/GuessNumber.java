package GuessNumber;

import java.util.*;

public class GuessNumber {
    public static void main(String[] args) {
        Random random = new Random();
        int times = 0;
        int guess = 0;
        int ans = random.nextInt(1000) + 1;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter an interger between 1 and 1000: ");
        while (guess != ans && ++times > 0) {
            System.out.print("Enter your guess: ");
            guess = sc.nextInt();
            if (guess == ans)
                System.out.println("Congratulations! Your guess " + guess + " is correct.\n");
            else if (guess > ans)
                System.out.println("Your guess " + guess + "is too large.");
            else
                System.out.println("Your guess " + guess + " is too low");
        }
        System.out.println("You have guessed " + times + " times.");
        sc.close();
    }
}
