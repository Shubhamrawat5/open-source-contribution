
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.*;

public class mydb{

        public static void main (String [] args){

           try{
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/practical", "root", "22558800");
            // Statement s1= con.createStatement();
            // ResultSet r1=s1.executeQuery("select * from department");
            PreparedStatement p1=con.prepareStatement("insert into department values(?,?,?,?)");
            PreparedStatement p2= con.prepareStatement("delete  from department where dept_id=(?)");
        //     p1.setString(1, "E-106");
        //     p1.setString(2, "sales");
        //     p1.setString(3, "Sunday");
        //     p1.setInt(4, 119);
            p2.setString(1, "E-102");



            p2.executeUpdate();

            System.out.println("table has been updated....");

            // while (r1.next()){
            //     System.out.println(r1.getString("dept_id")+"\t"+ r1.getString("dept_name"));

            // }
            

           }

           catch (Exception  e){
            System.out.println("Failed to create connection due to  "+e);

           }

        }


}