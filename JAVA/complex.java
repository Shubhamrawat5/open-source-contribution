package project2;


class complex{
    int num,num1;
  complex(int real,int image)
    {
        num=real;
        num1=image;
    }
   public String toString()
    {
        return num+"+i"+num1;
    }
      public static complex add(complex n1,complex n2)
    {
        complex temp=new complex(0,0);
      temp.num=n1.num+n2.num;
        temp.num1=n1.num1+n2.num1;
 return temp;
    }
      public static complex multiply(complex n1,complex n2)
      {
          complex temp=new complex(0,0);
          temp.num=n1.num*n2.num;
          temp.num1=n1.num1*n2.num1;
          return temp;
      }

//public class ques1_classroom 
    public static void main(String args[])
    {int a=Integer.parseInt(args[0]);
    int b=Integer.parseInt(args[1]);
        complex c1=new complex(a,b);
        String s1=c1.toString();
        complex c2=new complex(a,b);
            String s2=c2.toString();
        System.out.println("first complex number:-");
           System.out.println(s1);
                System.out.println("second complex number:-");
           System.out.println(s2);
       complex c3=c1.add(c1,c2);
       String x=c3.toString();
         System.out.print("addition of complex numbers are:="+"  "+x);
       complex c4=c1.multiply(c1,c2);
       String y=c4.toString();
       System.out.print("multiplication of complex numbers are:="+y);        
    }

}
