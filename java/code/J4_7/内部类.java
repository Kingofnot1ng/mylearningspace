package code.J4_7;



class Car{
    String brand="奔驰";
    //成员内部类
    class Engine{
        public void run(){
            System.out.println(brand+"发动机启动");
        }
    }
    //静态内部类
    static class Wheel{
        public void run(){
            // 静态内部类只能调用静态外部成员
            System.out.println("轮子转动");
        }
    }
}
class Outer{
    
    public void method(){
        //局部内部类
        class Inner{
            public void show() {
                System.out.println("局部内部类");
            }
        }
        Inner inner=new Inner();
        inner.show();
    }
}
public class 内部类 {
    public static void main(String[] args){
        Car.Engine engine1=new Car().new Engine();
        Car car1=new Car();
        Car.Engine engine2=car1.new Engine();
        Car.Wheel wheel1=new Car.Wheel();
        Outer outer=new Outer();
        engine1.run();
        engine2.run();
        wheel1.run();
        outer.method();
    }
}
