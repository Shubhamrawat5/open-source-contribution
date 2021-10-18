#include<iostream>
using namespace std;

void fillColor(int v[][4],int row,int col,int newcolor,int prevcolor){
  int rows = 4;
  int cols = sizeof(v[0])/sizeof(v[0][0]);

  //base condition
  //if we move out of the matrix 
  if(row >= rows || row < 0 || col >= cols || col < 0){
    return;
  }
  //if the current color is not equal to the color that has to be replaced
  if(prevcolor != v[row][col]){
    return;
  }

  v[row][col] = newcolor;
  //calling recursive function for top,bottom,left,right
  fillColor(v,row+1,col,newcolor,prevcolor);
  fillColor(v,row-1,col,newcolor,prevcolor);
  fillColor(v,row,col+1,newcolor,prevcolor);
  fillColor(v,row,col-1,newcolor,prevcolor);
}


void display(int v[][4]){
  int rows = 4;
  int cols = sizeof(v[0])/sizeof(v[0][0]);
   cout<<"Contents :"<<endl;
   for(int i=0;i<rows;i++){
       for(int j=0;j<cols;j++){
           cout<<v[i][j];
       }
       cout<<endl;
   }
}

int main(){
    //declared an array 
    int v[4][4] = {
        {1,2,0,1},
        {1,1,1,1},
        {0,0,1,1},
        {2,2,2,2}
    };
  
    //calling recursive function
    fillColor(v,0,0,4,1);

    //displaying the matrix
    display(v);
    return 0;
}