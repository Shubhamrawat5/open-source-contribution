#include<iostream>
using namespace std;
double a1[4][4];
double b1[4][4];

void insert(double z[4][4])
{
	double val;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>val;
			z[i][j]=val;
		}
	}
}
double cal11(double x[4][4])
{
	return (z[1][1] * z[1][2])+ (z[1][2] * z[2][1]);
}
double cal21(double x[4][4])
{
	return (z[3][1] * z[4][2])+ (z[3][2] * z[4][1]);
}

double cal12(double z[4][4])
{
	return (z[1][3] * z[2][4])+ (z[1][4] * z[2][3]);
}

double cal22(double z[4][4])
{
	return (z[2][3] * z[1][4])+ (z[2][4] * z[1][3]);
}

int main()
{
	double a11,a12,a22,a21,b11,b12,b21,b22,a1[4][4],b1[4][4];
	double p,q,r,s,t,u,v,c11,c12,c21,c22;
	cout<<"/n a: /n";
	insert(a1);
	cout<<"/n b: /n";
	insert(b1);
	a11=cal11(a1);
	a12=cal12(a1);
	a21=cal21(a1);
	a22=cal22(a1);
	b11=cal11(b1);
	b12=cal12(b1);
	b21=cal21(b1);
	b22=cal22(b1);
               p=(a11+a22)*(b11+b22);
	q=(a21+a22)*b11;
	r=a11*(b12-b22);
	s=a22*(b21-b11);
	t=(a11+a12)*b22;
	u=(a11-a21)*(b11+b12);
	v=(a12-a22)*(b21+b22);
cout<<"/n final matrix";
 	cout<<"/n"<<p+s-t+v<<" "<<r+t;
	cout<<"/n"<<q+s<<" "<<p+r-q+u;
    return 0;
}