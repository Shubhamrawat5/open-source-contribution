

class base {
      
       void message (){
        System.out.println("Greetings from base class");
       }


}


class derived extends base{

    void message(){
        System.out.println("Greetings from derived class");
    }
}


public class dynamic {

    public static void main(String[] args) {

          base  d1 = new derived();
          d1.message();
        
    }
    
}
