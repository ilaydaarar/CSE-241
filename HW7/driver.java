
import inner.DayofYearSet;
import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;
 /** 
  * @author Ilayda Arar
  * @since 2022-01-01
  */









 public class driver {
     public static void main (String args[]) {
        
        
        
         DayofYearSet.DayofYear doy1 = new DayofYearSet.DayofYear(8,2);
         DayofYearSet.DayofYear doy2 = new DayofYearSet.DayofYear(9,5);
         DayofYearSet.DayofYear doy3 = new DayofYearSet.DayofYear(2,10);
         


         ArrayList<DayofYearSet.DayofYear> mylist1 = new ArrayList<DayofYearSet.DayofYear>();

         
            mylist1.add(new DayofYearSet.DayofYear(1,2));
            mylist1.add(new DayofYearSet.DayofYear(8,3));
            mylist1.add(new DayofYearSet.DayofYear(11,9));
            mylist1.add(new DayofYearSet.DayofYear(4,3));
            mylist1.add(new DayofYearSet.DayofYear(5,7));
         
         ArrayList<DayofYearSet.DayofYear> mylist2 = new ArrayList<DayofYearSet.DayofYear>();

         
            mylist2.add(new DayofYearSet.DayofYear(4,2));
            mylist2.add(new DayofYearSet.DayofYear(6,3));
            mylist2.add(new DayofYearSet.DayofYear(11,9));
            mylist2.add(new DayofYearSet.DayofYear(4,3));
            mylist2.add(new DayofYearSet.DayofYear(5,7));

        ArrayList<DayofYearSet.DayofYear> mylist3 = new ArrayList<DayofYearSet.DayofYear>();

         
            mylist3.add(new DayofYearSet.DayofYear(4,2));
            mylist3.add(new DayofYearSet.DayofYear(6,3));
            mylist3.add(new DayofYearSet.DayofYear(7,9));
            mylist3.add(new DayofYearSet.DayofYear(2,3));
            mylist3.add(new DayofYearSet.DayofYear(7,7));
         
         DayofYearSet.DayofYear a = new DayofYearSet.DayofYear(1,3);
         DayofYearSet.DayofYear b = new DayofYearSet.DayofYear(3,3);



         DayofYearSet X = new DayofYearSet(mylist1);

         System.out.print("Total count of DayofYear objects is:");
         System.out.println(X.total_count());


         DayofYearSet Y = new DayofYearSet(mylist2);
         DayofYearSet Z = new DayofYearSet(mylist3);
         DayofYearSet Q = new DayofYearSet(mylist3);


         System.out.println("Testing ToString method with X and Y");
         X.ToString();
         Y.ToString();


         System.out.println("Testing equals method with X-Y and Z-Q");
         if(X.equals(Y)) System.out.println("They are same");
         else System.out.println("They are not same");
         if(Z.equals(Q)) System.out.println("They are same");
         else System.out.println("They are not same");

         System.out.println("Testing add method with X and Y");
         X.add(doy1);
         Y.add(doy2);
         X.ToString();
         Y.ToString();

         System.out.println("Testing remove method with Z and Y");
         Z.ToString();
         Y.ToString();
         Z.remove(1);
         Y.remove(2);
         Z.ToString();
         Y.ToString();
         System.out.print("Total count of DayofYear objects is:");
         System.out.println(X.total_count());
         
         System.out.println("Testing size method with Z");
         System.out.print("Size of Z:");
         System.out.println(Z.size());
         System.out.println("Testing size method with Y");
         System.out.print("Size of Y:");
         System.out.println(Y.size());



         DayofYearSet U = new DayofYearSet();
         DayofYearSet I = new DayofYearSet();
         DayofYearSet D = new DayofYearSet();
         DayofYearSet C = new DayofYearSet();



         System.out.println("Testing union method with X and Y");
         U = X.union(Y);
         U.ToString();
         System.out.println("Testing union method with X and Z");
         U = X.union(Z);
         U.ToString();

         System.out.println("Testing difference method with X and Y");
         D = X.diff(Y);
         D.ToString();
         System.out.println("Testing difference method with X and Z");
         D = X.diff(Z);
         D.ToString();

         System.out.println("Testing intersection method with X and Y");
         I = X.inter(Y);
         I.ToString();
         System.out.println("Testing intersection method with X and Z");
         I = X.inter(Z);
         I.ToString();


         System.out.println("Testing complement method with X");
         C = X.complement(X);
         System.out.println("*******************************************************");
         C.ToString();
         System.out.println("Testing complement method with Z");
         C = Z.complement(Z);
         System.out.println("*******************************************************");
         C.ToString();


         System.out.println("*******************************************************");

         System.out.println("Testing DeMorgan rules");


         DayofYearSet D1 = new DayofYearSet();
         DayofYearSet D2 = new DayofYearSet();
         DayofYearSet D3 = new DayofYearSet();
         DayofYearSet D4 = new DayofYearSet();
         DayofYearSet D5 = new DayofYearSet();
         

         D1 = X.union(Y);
         D2 = D1.complement(D1);

         D3 = X.complement(X);
         D4 = Y.complement(Y);
         D5 = D3.inter(D4);


         if(D2.equals(D5)) System.out.println("They are same");
         else System.out.println("They are not same");

         D1 = X.union(Z);
         D2 = D1.complement(D1);

         D3 = X.complement(X);
         D4 = Z.complement(Z);
         D5 = D3.inter(D4);


         if(D2.equals(D5)) System.out.println("They are same");
         else System.out.println("They are not same");

         D1 = Y.union(Z);
         D2 = D1.complement(D1);

         D3 = Z.complement(Z);
         D4 = Y.complement(Y);
         D5 = D3.inter(D4);


         if(D2.equals(D5)) System.out.println("They are same");
         else System.out.println("They are not same");

         D1 = U.union(I);
         D2 = D1.complement(D1);

         D3 = U.complement(U);
         D4 = I.complement(I);
         D5 = D3.inter(D4);


         if(D2.equals(D5)) System.out.println("They are same");
         else System.out.println("They are not same");

         D1 = Q.union(Y);
         D2 = D1.complement(D1);

         D3 = Q.complement(Q);
         D4 = Y.complement(Y);
         D5 = D3.inter(D4);


         if(D2.equals(D5)) System.out.println("They are same");
         else System.out.println("They are not same");

         try {
          FileWriter filew = new FileWriter("somesets.txt");
          filew.write(X.toString2());
          filew.write(Y.toString2());
          filew.write(Z.toString2());
          filew.write(Q.toString2());
          filew.write(C.toString2());
          filew.write(D1.toString2());
          filew.close();
          System.out.println("Successfully wrote some sets to the file.");
        } catch (IOException e) {
          System.out.println("An error occurred.");
          e.printStackTrace();
        }

         System.out.println("Program succesfully ended");
     }
} 
