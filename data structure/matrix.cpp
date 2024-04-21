#include <iostream>
using namespace std;
int main()
{

    int m1[100][100] , m2[100][100] , res[100][100];
    int r1,r2,c1,c2,i,j,k,sum=0;
    cout<<"Enter rows and column in matrix 1:\n";
    cin >> r1>>  c1;
    cout <<"Enter elements :\n";
    for ( i = 0; i < r1; i++)
    {
        for ( j = 0; j< c1; j++)
        {
            cin >> m1[i][j];
        }

    }

     cout<<"Enter rows and column in matrix 2:\n";
    cin >> r2>>  c2;
    cout <<"Enter elements :\n";
    for ( i = 0; i < r2; i++)
    {
        for ( j = 0; j< c2; j++)
        {
            cin >> m2[i][j];
        }

    }

if (r2!=c1){
    cout<<"Matrix multiplication is not possible"<<endl;
}
else{
      for ( i = 0; i < r1; i++)
    {
        for ( j = 0; j< c2; j++)
        {
            for ( k = 0; k < c1; k++)
            {
               sum+=m1[i][k]*m2[k][j];
            }
            res[i][j]=sum;
            sum=0;

        }

    }
}
    cout <<"Multiplication of two given matrix is :\n";

      for ( i = 0; i < r1; i++)
    {
        for ( j = 0; j< c2; j++)
        {
            cout<< res[i][j]<<" ";
        }
        cout<<endl;

    }








return 0;
}
