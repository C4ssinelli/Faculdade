import java.sql.*;

class Cria {
  public static void main(String[] args) {
    try {
      Class.forName("org.hsql.jdbcDriver");
      Connection con = DriverManager.getConnection("jdbc:HypersonicSQL:hsql://localhost:8080", "sa", "");
      Statement stmt = con.createStatement();
      stmt.executeUpdate("CREATE TABLE ESTOQUE (PRODUTO VARCHAR(30), QUANTIDADE INTEGER, CUSTO FLOAT, PRECO FLOAT)");
      stmt.close();
      con.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
