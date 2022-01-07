package code.J4_5;

abstract class Animal{
    public abstract void shout();
}

class Cat extends Animal{
    @Override
    public void shout(){
        System.out.println("小猫叫");
    }
}
class Dog extends Animal{
    @Override
    public void shout(){
        System.out.println("小狗叫");
    }
}
public class 多态{
    public static void main(String[] args){
        Cat cat1=new Cat();
        Dog dog1=new Dog();
        shout(cat1);
        shout(dog1);
    }
    public static void shout(Animal a){
        a.shout();
    }
}