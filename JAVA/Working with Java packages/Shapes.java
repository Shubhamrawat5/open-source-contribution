
class Rectangle {
    int l , b;
    int area;
    void getVal(int len , int brd){
        l=len;
        b=brd;
    }

    void area_rect(){
        area=l*b;
        System.out.println("Area is:"+area);
    }

}

class Cylinder{
    int rad , height;
    
    void getVal(int r , int h){
        rad=r;
        height=h;

    }
    void volume_cylinder(){
        System.out.println("Area is:"+3.14*rad*rad*height);
    }

}


class Square{
  int side;
    int area;
    void getVal(int s){
        side=s;
    }

    void area_sq(){
        area=4*side;
        System.out.println("Area is:"+area);
    }

}



public class Shapes {

   public static void main(String[] args) {
     
     int [] arr={1,2,3,4,5,6};
     for (int i : arr) {
         System.out.println(i);
     }


   }

}