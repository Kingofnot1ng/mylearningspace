package code.J3_3;

//封装Student属性
class Student{
    private String name;
    private int id;
    Student(){
        name="";
        id=0;
    }
    Student(String name,int id){
        this.name=name;
        this.id=id;
    }
    //访问器getter
    public String getname(){
        return this.name;
    }
    public int getid(){
        return this.id;
    }
    //修改器setter
    public void setname(String name){
        this.name=name;
    }
    public void setid(int id){
        this.id=id;
    }
}
public class 封装 {
    public static void main(String[] args){

    }
}
