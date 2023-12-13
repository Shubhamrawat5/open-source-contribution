#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<cctype>

using namespace std;

int determinant(int odr,int a[10][10])
{
	int det=0,d1,d2,d3;
	if(odr==2)
	return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
	else
	{
		d1=a[0][0]*(a[1][1]*a[2][2]-a[2][1]*a[1][2]);
		d2=a[0][1]*(a[1][0]*a[2][2]-a[2][0]*a[1][2]);
		d3=a[0][2]*(a[1][0]*a[2][1]-a[2][0]*a[1][1]);
		det=d1-d2+d3;
	}
	return det;
}

int rank(int odr,int a[10][10])
{
	int det=0,d1,d2,d3;
	if(odr==2)
	{
		det=(a[0][0]*a[1][1]-a[0][1]*a[1][0]);
		if(det==0)
		return 1;
		else 
		return 2;
	}	
	else
	{
		d1=a[0][0]*(a[1][1]*a[2][2]-a[2][1]*a[1][2]);
		d2=a[0][1]*(a[1][0]*a[2][2]-a[2][0]*a[1][2]);
		d3=a[0][2]*(a[1][0]*a[2][1]-a[2][0]*a[1][1]);
		det=d1-d2+d3;
		if(det!=0)
		return 3;
		else
		return 2;
	}
}
main()
{
	int n,row,col,odr,a[10][10],b[10][10],c[10][10],adj[5][5];
	char d;
	
	//Welcome Screen
	do
	{	
	cout<<"\t\t\t\t\tSelect one of the following\n"<<"\t\t\t\t\t***************************\n";
	cout<<"1. Addition of two matrices\n";
	cout<<"2. Subtraction of two matrices\n";
	cout<<"3. Multiplication of two matrices\n";
	cout<<"4. Determinant of Matrix\n";
	cout<<"5. Adjoint of Matrix\n";
	cout<<"6. Inverse of Matrix\n";
	cout<<"7. Rank of Matrix\n";
	cout<<"8. Quit\n";
	cout<<"\n********************************************\n\n";
	//taking choice input
	cin>>n;
	
	if(n==1 || n==2 || n==3)
	{
	//matrix elements
	cout<<"Enter the number of rows:\n";
	cin>>row;
	cout<<"Enter the number of columns:\n";
	cin>>col;
	
	cout<<"Enter the elements of first matrix(row wise)\n";
	for(int i=0;i<row;i++)
		{
				for(int j=0;j<col;j++)
				{
					cin>>a[i][j];
				}
			}
	cout<<"Enter the elements of second matrix(row wise)\n";
	for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					cin>>b[i][j];
				}
			}
	}
	if(n==4 || n==5 || n==6)
	{
		cout<<"Enter the Order of Matrix(Maximum Order=3)\n";
		cin>>odr;
		cout<<"Enter the elements of the matrix(row wise)\n";
		for(int i=0;i<odr;i++)
		{
			for(int j=0;j<odr;j++)
			{
				cin>>a[i][j];
			}
		}
	}
	if(n==7)
	{
		cout<<"Enter Order of Square Matrix(Maximum Order=3)\n";
		cin>>odr;
		cout<<"Enter the elements of the matrix(row wise)\n";
		for(int i=0;i<odr;i++)
		{
			for(int j=0;j<odr;j++)
			{
				cin>>a[i][j];
			}
		}
	}
	switch(n)
	{
		case 1:
			cout<<"Sum of the Matrices equals to\n";
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					c[i][j]=a[i][j]+b[i][j];
				}
			}
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					cout<<c[i][j]<<"\t";
				}
				cout<<endl;
			}
			break;
		case 2:
			cout<<"Subtraction equals to\n";
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					c[i][j]=a[i][j]-b[i][j];
				}
			}
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					cout<<c[i][j]<<"\t";
				}
				cout<<endl;
			}
			break;
		case 3:
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					c[i][j]=0;
					for(int k=0;k<col;k++)
					{
						c[i][j]+=a[i][k]*b[k][j];	
					}
				}
			}
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<col;j++)
				{
					cout<<c[i][j]<<"\t";
				}
				cout<<endl;
			}
			break;
		case 4:
			cout<<"Determinant of Matrix equals to:\n"<<determinant(odr,a)<<endl;
			break;
		case 5:
			if(odr==2)
		{
			adj[0][0]=pow(-1,2)*a[1][1];
			adj[0][1]=pow(-1,1)*a[0][1];
			adj[1][0]=pow(-1,1)*a[1][0];
			adj[1][1]=pow(-1,2)*a[0][0];
			cout<<"Adjoint of Matrix equals to:\n";
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					cout<<adj[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
		if(odr==3)
		{
			adj[0][0]=(a[1][1]*a[2][2])-(a[2][1]*a[1][2]);
			adj[0][1]=(a[1][2]*a[2][0])-(a[2][2]*a[1][0]);
			adj[0][2]=(a[1][0]*a[2][1])-(a[2][0]*a[1][1]);
			adj[1][0]=(a[2][1]*a[0][2])-(a[0][1]*a[2][2]);
			adj[1][1]=(a[0][0]*a[2][2])-(a[0][2]*a[2][0]);
			adj[1][2]=(a[2][0]*a[0][1])-(a[0][0]*a[2][1]);
			adj[2][0]=(a[0][1]*a[1][2])-(a[1][1]*a[0][2]);
			adj[2][1]=(a[1][0]*a[0][2])-(a[1][2]*a[0][0]);
			adj[2][2]=(a[1][1]*a[0][0])-(a[0][1]*a[1][0]);
			cout<<"Adjoint of Matrix equals to:\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<adj[i][j]<<"\t";
				}
				cout<<endl;
			}
		}
			break;
		case 6:
			if(odr==2)
		{
			adj[0][0]=pow(-1,2)*a[1][1];
			adj[0][1]=pow(-1,1)*a[0][1];
			adj[1][0]=pow(-1,1)*a[1][0];
			adj[1][1]=pow(-1,2)*a[0][0];
			cout<<"Inverse of Matrix equals to:\n";
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<2;j++)
				{
					cout<<adj[i][j]<<"/"<<determinant(odr,a)<<"\t";
				}
				cout<<endl;
			}
		}
		if(odr==3)
		{
			adj[0][0]=(a[1][1]*a[2][2])-(a[2][1]*a[1][2]);
			adj[0][1]=(a[1][2]*a[2][0])-(a[2][2]*a[1][0]);
			adj[0][2]=(a[1][0]*a[2][1])-(a[2][0]*a[1][1]);
			adj[1][0]=(a[2][1]*a[0][2])-(a[0][1]*a[2][2]);
			adj[1][1]=(a[0][0]*a[2][2])-(a[0][2]*a[2][0]);
			adj[1][2]=(a[2][0]*a[0][1])-(a[0][0]*a[2][1]);
			adj[2][0]=(a[0][1]*a[1][2])-(a[1][1]*a[0][2]);
			adj[2][1]=(a[1][0]*a[0][2])-(a[1][2]*a[0][0]);
			adj[2][2]=(a[1][1]*a[0][0])-(a[0][1]*a[1][0]);
			cout<<"Inverse of Matrix equals to:\n";
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cout<<adj[i][j]<<"/"<<determinant(odr,a)<<"\t";
				}
				cout<<endl;
			}
		}
			break;
		case 7:
			cout<<"Rank of Matrix equals to:\n"<<rank(odr,a)<<endl;
			break;
		case 8:
			exit(0);
			break;		
	}
	cout<<"********************************************";
	cout<<"\n\nDo you want to continue? (Y/N)\n";
	cin>>d;
	d=toupper(d);
	}while(d=='Y');
	return 0;
}
