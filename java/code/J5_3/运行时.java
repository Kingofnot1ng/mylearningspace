package code.J5_3;

import java.io.IOException;

public class 运行时 {
    public static void main(String[] args) throws IOException{
        Runtime runtime=Runtime.getRuntime();
        try {
            runtime.exec("notepad.exe");
        } catch (IOException e) {
            System.out.println("IOException!!");
        }
        System.out.println(runtime.freeMemory());
        System.out.println(runtime.maxMemory());
        System.out.println(runtime.totalMemory());
        System.out.println( runtime.availableProcessors());
    }
}
