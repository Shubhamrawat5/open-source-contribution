//***FLOATING POINT REPRESENTATION TO BINARY USING C++***

#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int decSize = 0;

int main()
{
    double n;
    cout<<"Enter the decimal number: ";
    cin>>n;
    int s;
    if(n>0)
    s=0;
    else 
    s=1;
    //Decimal part to binary 
    
    n = abs(n);
   int intPart = (int)n;
   double decPart = n - intPart;
   int *dbin = new int[23];
    for (int j = 0; j < 23; j++)
    {
        dbin[j] = 0;
    }
   int i = 0;
   while(decPart != 0 && i < 23)
   {
       decPart = decPart*2;
       int temp1 = (int) decPart;
       dbin[i] = temp1;
       decPart = decPart - temp1;
       i++;
   }
   
   //int part to binary 
   
    n = abs(n);
    intPart = (int) n;
    int *nbin = new int[8];
    for (int j = 0; j < 8; j++)
    {
        nbin[j] = 0;
    }
     i = 7;
    while (intPart > 0)
    {
        nbin[i] = intPart % 2;
        intPart = intPart/2;
        i--;
        decSize++;
    }
    
   
  //shifting decimal 
  
  int c=0;
   int a=0;
   while(nbin[a]!=1){
       c++;
       a++;
   }
   int e=8-(c+1);
     e=127+e;
   
   //convert exponent to binary form 
   
   e= abs(e);
    int *exponent= new int[8];
    for (int j = 0; j < 8; j++)
    {
        exponent[j] = 0;
    }
     i = 7;
    while (e> 0)
    {
        exponent[i] = e % 2;
        e= e/2;
        i--;
        decSize++;
    }
 int *mantissa= new int[23];
  int k=c+1;
 for(int d=0;d<8-(c+1)&&k<8;d++){
     mantissa[d]=nbin[k];
     k++;
 }
 int g=0;
 for(int f=8-(c+1);f<23;f++){
     mantissa[f]=dbin[g];
     g++;
     
 }
   
   cout<<"S "<<"     EXPONENT     "<<"      MANTISSA           "<<endl;
   cout<<s<<"     ";
   for(int i=0;i<8;i++)
   cout<<exponent[i];
   cout<<"     ";
   for(int i=0;i<23;i++)
   cout<<mantissa[i];
  }
