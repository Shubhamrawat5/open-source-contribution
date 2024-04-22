import Shapes.BasicShapes.*;


public class testclass {
    public static void main(String[] args) {
           Rectangle r1=new Rectangle();
           Square  s1=new Square();
           Cylinder c1=new Cylinder();
           r1.getVal(6, 2);
           r1.area_rect();
           s1.getVal(12);
           s1.area_sq();
           c1.getVal(5, 12);
           c1.volume_cylinder();
    }
    
}
