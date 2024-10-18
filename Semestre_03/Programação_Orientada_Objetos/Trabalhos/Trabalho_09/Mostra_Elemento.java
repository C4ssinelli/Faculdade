import java.sql.*;

class Select {
  public static void main(String[] args) {
    try {
      Class.forName("org.hsql.jdbcDriver");
      Connection con = DriverManager.getConnection("jdbc:HypersonicSQL:hsql://localhost:8080", "sa", "");
      Statement stmt = con.createStatement();
      ResultSet rs = stmt.executeQuery("SELECT * FROM ESTOQUE");//Para mostrar a tabela completa
      //ResultSet rs = stmt.executeQuery("SELECT * FROM ESTOQUE WHERE PRODUTO LIKE 'C%'");//Para mostrar os produtos com C no nome
      while (rs.next()) {
        String s = rs.getString("PRODUTO");
        Integer n = rs.getInt("QUANTIDADE");
        float c = rs.getFloat("CUSTO");
        float p = rs.getFloat("PRECO");
        System.out.println("PRODUTO: " + s + "\n" + "QUANTIDADE: " + n + "\n" + "CUSTO: " + c + "\n" + "PRECO: " + p + "\n");
      }
      stmt.close();
      con.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
