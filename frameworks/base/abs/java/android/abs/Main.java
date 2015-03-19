package android.abs;

public class Main {
  public static void main (String[] args) {
      try {
          Abs.putData("Hello ABS");
          String out = Abs.getData();
          System.out.println(out);
          Abs.clear();
      } catch (Exception e) {
          System.out.println(e.toString());
      }
  }
}
