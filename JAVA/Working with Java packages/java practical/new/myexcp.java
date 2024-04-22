class myexception extends Exception{

      

       myexception(String s){
        super(s);
       }
}


class test {
     int x;
     test(int x){

        this.x=x;
     }
    void display() throws myexception{
          if (x==0){
            throw new  myexception("Error is occured");
          }

          else {
            System.out.println("Value is:"+x);
          }
    }
}

public class myexcp {
    public static void main(String[] args) {

      //   test t1 =new test(0);

      //  try{
      //     t1.display();
      //  }

      //  catch (Exception e){
      //   System.out.println(e);
      //  }


      int x=87;
      int y=0;
      try{

           if (y>0){
            System.out.println(x/y);
           }
           else {
            throw new ArithmeticException("Cannot be divide by zero");
           }
      }
      catch (Exception e){
         System.out.println(e);
      }


          

    }
    
}
