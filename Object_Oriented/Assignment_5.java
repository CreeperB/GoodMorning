import java.util.Scanner;

public class Assignment_5 {

  static String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  static String encodeBook = "ICOXDPBUQJARHKNGWYLEZSVFMT";

  static String encrypt(String keyword, String text) {
    String result = "";
    int keywordIndex = 0;
    for (int i = 0; i < text.length(); i++) {
      char c = text.charAt(i);
      if (Character.isLetter(c)) {
        int encodeBookIndex = encodeBook.indexOf(keyword.charAt(keywordIndex));
        int alphabetIndex = alphabet.indexOf(c);
        int encryptedIndex = (encodeBookIndex + alphabetIndex) % alphabet.length();
        result += encodeBook.charAt(encryptedIndex);
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
        int encodeBookIndex = encodeBook.indexOf(keyword.charAt(keywordIndex));
        int alphabetIndex = encodeBook.indexOf(c);
        int decryptedIndex = (alphabetIndex - encodeBookIndex + alphabet.length()) % alphabet.length();
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

    System.out.print("Enter the keyword: ");
    String keyword = scanner.nextLine().toUpperCase();

    System.out.print("Enter the original text: ");
    String text = scanner.nextLine().toUpperCase();

    scanner.close();

    System.out.println("Uppercase text: " + text);

    String encryptedText = encrypt(keyword, text);
    System.out.println("Encrypted text: " + encryptedText);

    String decryptedText = decrypt(keyword, encryptedText);
    System.out.println("Decrypted text: " + decryptedText);
  }
}