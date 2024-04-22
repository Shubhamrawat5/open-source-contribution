import javax.print.DocFlavor.STRING;

class mythread extends Thread{

    mythread(String s){
        super(s);
    }


    public void run (){

        int i=15;
        try{
        while(i>0){
              System.out.println("Currently running thread: "+ currentThread().getName());
              currentThread().sleep(4000);
              i--;
        }
    }

    catch( Exception e){
        System.out.println(e);
    }
    }
}

class mythreadclass implements Runnable{

    public void run(){

        int i=0 ;
        while (i<=10){
            System.out.println("threading is running using runnable interface with ID:"+ Thread.currentThread().getId());
            i++;
        }

    }
}


public class threadtest {
    public static void main(String[] args) {

        mythread t1 =new mythread("T1");
        
        mythread t2 =new mythread("T2");

        mythreadclass r1=new mythreadclass();

        Thread t3=new Thread( r1);
        Thread t4=new Thread( r1);
        
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        
        
    }
    
}
