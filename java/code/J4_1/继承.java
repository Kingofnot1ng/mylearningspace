/**
 * 继承案例，继承关键字为extends
 */
package code.J4_1;

class Animal {
    private String name;
    private int age;
    Animal(){
        this.name="";
        this.age=0;
    }
    Animal(String name,int age){
        this.name=name;
        this.age=age;
    }
    public String getname(){
        return this.name;
    }
    public int getage(){
        return this.age;
    }
    public void setname(String name){
        this.name=name;
    }
    public void setage(int age){
        this.age=age;
    }
    public void speak(){
        System.out.println("动物叫");
    }
    public void print(){
        System.out.println(this.name+","+this.age);
    }
}

/*
    方法重写,需要子类的方法名，参数列表，返回值类型与父类相同 
    super关键字访问父类
        1.super.成员变量
        2.super.成员方法
        3.super()父类构造方法
*/

class Dog extends Animal {
    Dog(){
        super();
    }
    Dog(String name,int age){
        super(name,age);
    }
    @Override
    public void speak(){
        System.out.println("狗吠");
        super.speak();
    }
}

class Cat extends Animal {
    Cat(){
        super();
    }
    Cat(String name,int age){
        super.setname(name);
        super.setage(age);
    }
    @Override
    public void speak(){
        System.out.println("猫叫");
        super.speak();
    }
}
public class 继承 {
    public static void main(String[] args){
        Animal animal1=new Animal();
        Dog dog1=new Dog();
        Cat cat1=new Cat();
        animal1.speak();
        dog1.speak();
        cat1.speak();

        Dog dog2=new Dog("旺财",2);
        Cat cat2=new Cat("咪咪",3);
        dog2.print();
        cat2.print();
    }
}
