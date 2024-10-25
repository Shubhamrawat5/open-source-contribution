import java.util.Scanner;

class LengthOfLastWord
{
    //method - lastword chi length print karnya sathi
    public int LastWordLength(String s){
        int i = s.length()-1;
        while(i>=0 && s.charAt(i) == ' '){
            --i;
        }
        int j = i;
        while(j>=0 && s.charAt(j) != ' '){
            --j;
        }
        return i-j;
    }
    // method - lastword print karanya sathi
    public String Lastword(String s){
        s = s.trim();
        int lastspaceindex = s.lastIndexOf(' ');
        return s.substring(lastspaceindex +1);
    }


    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your Sentence : ");
        String sen = scanner.nextLine();

        LengthOfLastWord obj = new LengthOfLastWord();
        int Length = obj.LastWordLength(sen);
        String Lastword = obj.Lastword(sen);
        System.out.println("length of lastword : "+Length);
        System.out.println("Last word : "+Lastword);

    }

}