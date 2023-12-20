import java.util.Scanner;

public class VigenereSquare {

  static String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  static String encrypt(String keyword, String text) {
    String result = "";
    int keywordIndex = 0;
    for (int i = 0; i < text.length(); i++) {
      char c = text.charAt(i);
      if (Character.isLetter(c)) {
        int alphabetIndex = alphabet.indexOf(c);
        int keywordCharIndex = alphabet.indexOf(keyword.charAt(keywordIndex));
        int encryptedIndex = (alphabetIndex + keywordCharIndex) % alphabet.length();
        result += alphabet.charAt(encryptedIndex);
        keywordIndex = (keywordIndex + 1) % keyword.length();
      } else {
        result += c;
      }
    }

    return result;
  }

  static String decrypt(String keyword, String text) {
    String result = "";
    int keywordIndex = 0;
    for (int i = 0; i < text.length(); i++) {
      char c = text.charAt(i);
      if (Character.isLetter(c)) {
        int alphabetIndex = alphabet.indexOf(c);
        int keywordCharIndex = alphabet.indexOf(keyword.charAt(keywordIndex));
        int decryptedIndex = (alphabetIndex - keywordCharIndex + alphabet.length()) % alphabet.length();
        result += alphabet.charAt(decryptedIndex);
        keywordIndex = (keywordIndex + 1) % keyword.length();
      } else {
        result += c;
      }
    }

    return result;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Keyword: ");
    String keyword = scanner.nextLine().toUpperCase();

    System.out.print("Original Text: ");
    String text = scanner.nextLine().toUpperCase();

    scanner.close();

    System.out.println("Uppercase Text: " + text);

    String encryptedText = encrypt(keyword, text);
    System.out.println("Encrypted Text: " + encryptedText);

    String decryptedText = decrypt(keyword, encryptedText);
    System.out.println("Decrypted Text: " + decryptedText);
  }
}