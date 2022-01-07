package code;

public class Method{
    public static void main(String[] args) {
        method();
        Method m=new Method();
        m.method2();
    }
    private static void method(){
        System.out.println("method");
    }
    private void method2(){
        System.out.println("method2");
    }
}