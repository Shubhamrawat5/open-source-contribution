public class Details {
 
  public int BinaryToDecimal(int binaryNumber){
 
    int decimal = 0;
    int p = 0;
    while(true){
      if(binaryNumber == 0){
        break;
      } else {
          int temp = binaryNumber%10;
          decimal += temp*Math.pow(2, p);
          binaryNumber = binaryNumber/10;
          p++;
       }
    }
    return decimal;
  }
 
  public static void main(String args[]){
    Details obj = new Details();
    System.out.println("110 --> "+obj.BinaryToDecimal(110));
    System.out.println("1101 --> "+obj.BinaryToDecimal(1101));
    System.out.println("100 --> "+obj.BinaryToDecimal(100));
    System.out.println("110111 --> "+obj.BinaryToDecimal(110111));
  }
}
