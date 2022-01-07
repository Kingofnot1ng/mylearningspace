package code.J3_2;

public class J3_2{
    public static void main(String[] args){
        //先声明，再实例化对象
        J3_2 j1;
        j1=new J3_2();

        // 声明的同时实例化对象
        J3_2 j2=new J3_2();

        System.out.println(j1);
        System.out.println(j2);

        //对象的引用传递
        J3_2 j3=j2;
        System.out.println(j3);
    }
}
