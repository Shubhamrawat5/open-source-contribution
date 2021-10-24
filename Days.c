#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
bool leapyear(int y)
{
        if(y%100==0)
        {
            if(y%400==0)
            {
                return 1;
            }
            else return 0;
        }
        else if(y%4==0)
        {
            return 1;
        }
        else return 0;
}
long calcleapyears(int y)
{
    int cnt=0;
    for(int i=0;i<=y;i++)
    {
        if(leapyear(i)==1)
        {
            cnt++;
        }
        else continue;
    }
    return cnt;
}
int calcdaysinmonth(int m, int y)
{
    int sum=0;
    for(int i=1;i<m;i++)
    {
        if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
        {
            sum+=31;
        } 
        else if(i==4 || i==6 || i==9 || i==11)
        {
            sum+=30;
        }
        else if(i==2)
        {
            if(leapyear(y)==1)
            {
                sum+=29;
            }
            else if(leapyear(y)==0)
            {
                sum+=28;
            }
        }
    }
    return sum;
}
bool checkdate(int d,int m,int y)
{
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
    {
        if(d==0 || d>31)
        {
            return 0;
        }
        else if(d>0 && d<32)
        {
            return 1;
        }
    }
    else if(m==4 || m==6 || m==9 || m==11)
    {
        if(d==0 || d>30)
        {
            return 0;
        }
        else if(d>0 && d<31)
        {
            return 1;
        }
    }
    else if(m==2)
    {
        if(leapyear(y)==1)
        {
            if(d==0 || d>29)
            {
                return 0;
            }
            else if(d>0 && d<30)
            {
                return 1;
            }
        }
        else if(leapyear(y)==0)
        {
            if(d==0 || d>28)
            {
                return 0;
            }
            else if(d>0 && d<29)
            {
                return 1;
            }
        }
    }
}
int main()
{
    int d1,m1,y1,d2,m2,y2;
    printf("Enter the earlier date d1(dd mm yyyy) : ");
    scanf("%d %d %d",&d1,&m1,&y1);
    printf("Enter the later date d2(dd mm yyyy) : ");
    scanf("%d %d %d",&d2,&m2,&y2);
    long long sum1=0,sum2=0,sum;

    sum1=( (y1-calcleapyears(y1))*365 ) + (calcleapyears(y1)*366);
    if(m1==0 || m1>12)
    {
        printf("The input month in date d1 is wrong!!!");
        exit(0);
    }
    else if(m1>0 && m1<13)
    {
    sum1+=calcdaysinmonth(m1,y1);
    }
    if(checkdate(d1,m1,y1)==1)
    {
        sum1+=d1;
    }
    else if(checkdate(d1,m1,y1)==0)
    {
        printf("The input date in d1 is wrong!!!");
        exit(0);
    }

    sum2=( (y2-calcleapyears(y2))*365 ) + (calcleapyears(y2)*366);
    if(m2==0 || m2>12)
    {
        printf("The input month in date d2 is wrong!!!");
        exit(0);
    }
    else if(m2>0 && m2<13)
    {
    sum2+=calcdaysinmonth(m2,y2);
    }
    if(checkdate(d2,m2,y2)==1)
    {
        sum2+=d2+1;
    }
    else if(checkdate(d2,m2,y2)==0)
    {
        printf("The input date in d2 is wrong!!!");
        exit(0);
    }
    if(sum1>sum2)
    {
        printf("The dates entered are in wrong order!!!");
        exit(0);
    }

    sum=sum2-sum1;
    printf("The total number of days between two given dates is : %Ld \n",sum);
    exit(0);
}
