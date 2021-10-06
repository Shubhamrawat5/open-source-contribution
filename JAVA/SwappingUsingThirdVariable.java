class Swap_With {  
    public static void main(String[] args) {  
       int x, y, t;   
       Scanner sc = new Scanner(System.in);  
       System.out.println("Enter the value of X and Y");  
       x = 10;
       y = 20;  
       System.out.println("before swapping numbers: "+x +"  "+ y);  
       /*swapping */  
       t = x;  
       x = y;  
       y = t;  
       System.out.println("After swapping: "+x +"   " + y);  
       System.out.println( );  
    }    
} 
