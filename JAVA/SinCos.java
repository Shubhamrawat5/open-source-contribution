//Q:: Create a class myMath. The class contains the following static methods.
i) power (x, y) – to compute x y
ii) fact (x) – to compute x!
Write a program to find the following series.
●	cos (x) = 1 – (x2/2!) + (x4/4!) – (x6/6!) + … upto n terms (n given by user).
●	sin (x) = x-x3/3!+x5/5!-x7/7!+........ upto n terms (n given by user).




import java.util.*;
class MyMath
{

public static void main(String[]args){
int n;
float deg;
double pi=3.14;
Scanner sc =new Scanner(System.in);
System.out.println("enter the number of terms");
n=sc.nextInt();
System.out.println("enter the angle : ");
deg=sc.nextInt();
deg=(float)(deg*pi)/180;
int ch;
System.out.println("which series do you want to print :1:sine,2:cos");
ch=sc.nextInt();
switch(ch){
case 1:
float sinx=sine(deg,n);
System.out.println("the sine value is : "+sinx);
break;
case 2:
float cosx=cosine(deg,n);
System.out.println("the cosine value is : "+cosx);
break;
default:
System.out.println("wrong choice");
}
}

static float sine(float x, int n)
{
float sum=0;
int c=1;
for(int i=1;i<=n;i++)
{
if(i%2==1)
{
sum+=(power(x,c)/fact(c));
}
else
{
sum-=(power(x,c)/fact(c));
}
c+=2;
}
return sum;
}

static float cosine(float x, int n)
{
float sum=0;
int c=0;
for(int i=1;i<=n;i++)
{
if(i%2==1)
{
sum+=(power(x,c)/fact(c));
}
else
{
sum-=(power(x,c)/fact(c));
}
c+=2;
}
return sum;
}

static float power(float a,float b)
{
if (b != 0)
return (a * power(a,b - 1));
else
return 1;
}

 /*static float fact(float d)
{
float pow=1;
for(int i=1;i<=d;i++)
{
pow*=i;
}
return pow;
}*/

static float fact(float d)
{
if(d!=0)
return (d*fact(d-1));
else 
return 1;
    }
}

