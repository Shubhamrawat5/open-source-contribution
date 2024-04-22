
class ageException extends Exception{
       
    ageException(String s){
        super(s);
    }


}


class Validator {

      int age;

      Validator(int x ){
        this.age=x;
      }

      void check() throws ageException{
           
            if (age < 0){
                throw new ageException("Invalid age is entered");
            }
            else {
                if (age >= 18 ){
                    System.out.println("Eligible to vote");
                }

                else {

                    System.out.println("Not Eligible to vote");
                }
            }

      }
}


public class age {

    public static void main(String[] args) {

        Validator v1=new Validator(-30);

        try{
            v1.check();
        }

        catch (Exception e){
            System.out.println(e);
        }
        

        
        
    }
    
}
