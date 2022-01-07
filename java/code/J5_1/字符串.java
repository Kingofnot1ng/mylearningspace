package code.J5_1;

public class 字符串{
    public static void main(String[] args){
        StringBuffer stringBuffer=new StringBuffer();
        stringBuffer.append('a')
                    .append("b")
                    .append('c');
        System.out.println(stringBuffer.toString());
        stringBuffer.insert(2,'1');
        System.out.println(stringBuffer.toString());
        stringBuffer.deleteCharAt(2);
        System.out.println(stringBuffer.toString());
        stringBuffer.delete(0, 1);
        System.out.println(stringBuffer.toString());
        stringBuffer.replace(0, 1, "ab");
        System.out.println(stringBuffer.toString());
        stringBuffer.setCharAt(0, 'A');
        System.out.println(stringBuffer.toString());
        stringBuffer.reverse();
        System.out.println(stringBuffer.toString());
    }
}