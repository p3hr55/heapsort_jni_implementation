import java.util.Scanner;
import java.nio.*;
import java.io.*;

public class Call 
{
   static { System.loadLibrary("sort"); }
 
   private native int[] Heapsort(int[] numbers);
 
   public static void main(String args[]) throws FileNotFoundException, IOException {
      long start, stop;
      int b, e;
      Scanner input = new Scanner(System.in);
      System.out.print("Enter File name of file to sort ->");
      String choice = input.next();
      Scanner data = new Scanner(new File(choice));
      int[] myInts = new int[getEls(data)];
      data = new Scanner(new File(choice));
      
      for(int i = 0; i < myInts.length && data.hasNextInt(); i++) {  
         myInts[i] = data.nextInt();
      }

      start = System.currentTimeMillis();
      int[] sorted = new Call().Heapsort(myInts);
      stop = System.currentTimeMillis();
      
      System.out.println("\nSorted: " + (issorted(sorted) ? "Yes" : "No")); 
      System.out.println("Took " + (stop - start) + " milliseconds");
      
      System.out.print("\nEnter the index of where you want to start printing ->");
      b = input.nextInt();
      System.out.print("Enter the index of where you want to stop printing ->");
      e = input.nextInt();
      
      while(b < e)
         System.out.print(sorted[b++] + " ");
                
   }
   static int getEls(Scanner s) {
      int num = 0;
      while(s.hasNextInt()){
         s.nextInt();
         ++num;
      } 
      return num;
   }
   static boolean issorted(int[] ar) {
      for(int i = 2; i < ar.length; i++)
         if(ar[i] < ar[i - 1])
            return false;
      return true;
   }
}