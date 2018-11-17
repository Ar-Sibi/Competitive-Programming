import java.io.*;
import java.util.Scanner;
public class A{
    public static void main(String[] args){
        int[] colors= new int[26];
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int friends = s.nextInt();
        int totalcount=0;
        String str;
        s.nextLine();
        str = s.nextLine();
        for(int i=0;i<n;i++){
        colors[str.charAt(i)-'a']++;
        totalcount++;
        }
        for(int i=0;i<26;i++){
            if(colors[i]>friends){
                System.out.println("NO");
                return ;
            }
        }
        System.out.println("YES");
    }
}