#include <iostream>
using namespace std;
class Encrypt{

     
     public:
     Encrypt(char str[] , int key){
        int i=0;
        while (str[i]!='\0')
        {
            str[i]+=key;
            i++;

        }
        cout<<"Encryption is done.....";
        
     }
     


    

};
int main()
{

    char text[50];
    int key;
    cout <<"Enter text:";
    cin>> text;
    cout <<"Enter key :";
    cin>> key;
    Encrypt t1(text , key);
    cout<<"\nEncrypted text is :"<< text;
   
    
return 0;
}
