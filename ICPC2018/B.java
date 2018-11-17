import java.io.*;
import java.util.*;
public class B{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        long t;
        t=s.nextLong();
        while(t--!=0){
            long n,k;
            n=s.nextLong();
            k=s.nextLong();
            List<Long> arr = new ArrayList<Long>();
            for(int i=0;i<n;i++){
                arr.add(s.nextLong());
            }
            Collections.sort(arr);
            for(int i=0;i<n-1;i++){
            if(arr.get(i)<k){
			}else{
				long val=arr.get(i)-k;
				arr.set(i,arr.get(i)-val);
				arr.set(i+1,arr.get(i+1)-val);
			}
            }
            long sum=0;
            for(int i=0;i<n;i++)
            	sum+=arr.get(i);
		System.out.println(sum);
        }
    }
}