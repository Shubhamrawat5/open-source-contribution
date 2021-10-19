import java.util.Scanner;

public class WhitespaceRemover {
    public static void main(String[] args) {
        System.out.println("Input you phrase here");
        Scanner scan=new Scanner(System.in);
        String str=scan.nextLine();
        //1st way
        String noSpaceStr = str.replaceAll("\\s", ""); // using built in method
        System.out.println(noSpaceStr);
        //2nd way
        char[] strArray = str.toCharArray();
        StringBuilder stringBuffer = new StringBuilder();
        for (char c : strArray) {
            if ((c != ' ') && (c != '\t')) {
                stringBuffer.append(c);
            }
        }
        String noSpaceStr2 = stringBuffer.toString();
        System.out.println(noSpaceStr2);
    }
}
