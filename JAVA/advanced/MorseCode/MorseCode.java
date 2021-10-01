import java.util.Scanner;

public class MorseCode {
    public static void main(String[] args) throws NumberFormatException {
        String code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                        ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                        "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};  
    
            String res = "sunil patidar";
            String ans = res.toUpperCase();
            for(int i = 0; i < ans.length(); i++){
            int ascii = ans.charAt(i);
            if(!Character.isWhitespace(ascii)) // Check if not white space print the char
            System.out.print(code[ascii - 65] + " ");                      
        }
    }
}