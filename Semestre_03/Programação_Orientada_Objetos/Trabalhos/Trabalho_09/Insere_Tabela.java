import java.sql.*;

class Insere {
  public static void main(String[] args) {
    try {
      Class.forName("org.hsql.jdbcDriver");
      Connection con = DriverManager.getConnection("jdbc:HypersonicSQL:hsql://localhost:8080", "sa", "");
      Statement stmt = con.createStatement();
      stmt.executeUpdate("INSERT INTO ESTOQUE " + "VALUES ('CAFE', 10, 1.50, 1.75)");
      stmt.executeUpdate("INSERT INTO ESTOQUE " + "VALUES ('PAO', 5, 2.50, 3.50)");
      stmt.executeUpdate("INSERT INTO ESTOQUE " + "VALUES ('LEITE', 15, 0.75, 2.00)");
      stmt.close();
      con.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
