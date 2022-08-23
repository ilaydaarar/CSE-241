

package inner;
import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;

 /** 
  * @author Ilayda Arar
  * @since 2022-01-01
  * @version 1.0
  * DayofYearSet class holds DayofYear objects as day and month, in an array.
  */




public class DayofYearSet{ 


    private DayofYear[] container;
    private int capacity;
    static int count = 0;

    /**
     * @param Takes an Arraylist of DayofYear.
      */
    public DayofYearSet(ArrayList<DayofYearSet.DayofYear> con_list){ //Constructor for Arraylist
            
            int control = 1;
            int adding = 0;
            
            
            container = new DayofYear[360];
            DayofYear[] dummy = new DayofYear[con_list.size()]; //Copies the elements of con_list to an array
            for(int i = 0; i<con_list.size(); ++i){
                dummy[i] = con_list.get(i);
             }

            for (int j=0; j<con_list.size(); ++j) {
  
                control = 1;
                for(int k = j+1; k<con_list.size(); ++k){

                    if(dummy[j].day == dummy[k].day && dummy[j].month == dummy[k].month){
                        
                        control = 0;
                    } 
                }
                if(control == 1) {
                    container[adding] = dummy[j];   //If there is not a same element in the array, adding it to the container
                    adding++;

                }
            }

           
             capacity = adding; //Setting the capacity

        }

    /**
     * @param Takes an object of DayofYearSet.
      */
    public DayofYearSet(DayofYearSet myarray){  //Copy constructor
            
            container = new DayofYear[360];

             for(int i = 0; i< myarray.capacity; ++i){
                container[i] = myarray.container[i];
             }
             capacity = myarray.capacity; 
            
        }

    /**
     * @param Takes an array of DayofYear and counter.
      */
    public DayofYearSet(DayofYear [] myarray, int counter){ //Constructor for array
            
            container = new DayofYear[myarray.length]; 
            int i;
            
            
             for(i = 0; i< counter; ++i){
                container[i] = myarray[i];
             }
             capacity = counter; 
            
        }

        /**
         * Takes an integer and makes a full 360 day of object 
         * @param Takes an integer */
    public DayofYearSet(int c){ 
            
            container = new DayofYear[360];
            int i,j;
            int counter = 0;

            DayofYear[] dummy = new DayofYear[360];

            for(i=1;i<13;i++){

                for(j=1;j<31;j++){
                    
                    DayofYearSet.DayofYear N = new DayofYearSet.DayofYear(j,i); //Making an object to copy
                   
                    
                    dummy[counter] = N;
                    counter++;    
                    
                }
            }
            for(i = 0; i< counter; ++i){
                container[i] = dummy[i];    //Copying to the container
             }
           
             
             capacity = counter; 
            
        }

        /**
         * Makes an empty object
         */ 
    public DayofYearSet(){
            
            container = new DayofYear[360];
            
            capacity = 0; 
            
        }

        /** 
         * Overwritten tostring method, prints the DayofYearSet details. 
         * */
    public void ToString(){
        System.out.print("{ ");
        for(int i=0; i<capacity; ++i){
            System.out.print("(");
            System.out.print(container[i].getday());
            System.out.print(",");
            System.out.print(container[i].getmonth());
            System.out.print(")");
            System.out.print(",");

        }
        System.out.print(" }");
        System.out.print("\n");
    }

    /** 
         * Overwritten tostring method, prints the DayofYearSet details to a text file. 
         * @return mystring
          */
    public String toString2(){
        String mystring;
        mystring = "{ ";
        for(int i=0; i<capacity; ++i){
            
            mystring = mystring + "(";
            mystring = mystring + this.container[i].getday() + "," + this.container[i].getmonth() + ")" + ",";
            

        }
        
        mystring = mystring + " }" + "\n";
        
        return mystring;
    }

    /**
     * Controls if 2 DayofYearSet objects are equal or not.
     * @param DayofYearSet obj
     * @return control
     * */
    public boolean equals(DayofYearSet obj){

        boolean control = false;
        int match = 0;
        
        var i = 0;
        var j = 0;
        

        if(obj.capacity == capacity){

        for(i=0; i<capacity; i++){
            
            for(j=0; j<capacity; j++){
                if(container[i].day == obj.container[j].day && container[i].month == obj.container[j].month) {  //If there is a match, increment it
                    
                    match++;
                }
                
            }
        }
        }
        if(match == capacity) control = true; //If the match count and the length of the array is same, they are the same.
        else control = false;
        return control;
    }
    
    /**
     * @param DayofYear object
     * Adds a new element at the end of the container
     * */
    public void add(DayofYear obj){ 

        DayofYearSet.DayofYear a = new DayofYearSet.DayofYear(obj.getday(),obj.getmonth());
        int control = 1;
        for(int i=0; i<capacity; ++i){
           
            if(obj.day == container[i].day && obj.month == container[i].month){
                control = 0;

            } 
        }
        if(control == 1){
 
            container[capacity] = a;
            container[capacity].setday(a.getday());
            container[capacity].setmonth(a.getmonth());
            capacity++;
            
        }
        

    }

    /**
     * @return capacity
     * Returns the size of the container
     * */
    public int size(){
        return capacity;
    }

    /**
     * Removes an element from the wanted index
     * @param index
     * */

    public void remove(int index){

        for(int i = index; i< capacity-1; ++i){
            container[i] = container[i+1];
        }
        capacity = capacity - 1;
        count--;
    }

    /**
     * @param DayofYearSet obj 
     * @return DayofYearSet
     * Finds the set union */
    public DayofYearSet union(DayofYearSet set2){

        int control = 1;
        int counter = 0;
        DayofYear[] dummy = new DayofYear[360];

        for(int i = 0; i<capacity; i++){ 

            dummy[i] = container[i];
            counter++;
        }
        for(int i = 0; i<set2.capacity; i++){
            control = 1;
            for(int l=0; l<capacity; l++){
            
                
                    if(set2.container[i].day == container[l].day && set2.container[i].month == container[l].month) {  //If there is the same element in the second set, ignore it. If not, add it to the array.
                        control = 0;
                        
                    }
                    
                
             }
            if(control == 1){
            dummy[counter] = set2.container[i];    
            //vec.push_back(set2[i].day);
            //vec.push_back(set2[i].month);
            counter++;
            }
        }

        DayofYearSet U = new DayofYearSet(dummy,counter);
        return U;   //Return the new constructed union object.


    }

    /**
     * @param DayofYearSet obj 
     * @return DayofYearSet
     * Finds the set difference */
    public DayofYearSet diff(DayofYearSet set2){

        int control = 1;
        int counter = 0;
        DayofYear[] dummy = new DayofYear[360];

       
        for(int i = 0; i<capacity; i++){
            control = 1;
            for(int l=0; l<set2.capacity; l++){
            
                
                    if(set2.container[l] == container[i]) {  //If there is the same element in the second set, ignore it. If not, add it to the array.
                        
                        control = 0;
                        
                    }
                    
                
             }
            if(control == 1){
            dummy[counter] = container[i];    
            counter++;
            }
        }

        DayofYearSet U = new DayofYearSet(dummy,counter);
        return U;   //Return the new constructed union object.


    }

    /**
     * @param DayofYearSet obj 
     * @return DayofYearSet
     * Finds the set intersection */
    public DayofYearSet inter(DayofYearSet set2){

        int control = 1;
        int counter = 0;
        DayofYear[] dummy = new DayofYear[360];

       
        for(int i = 0; i<capacity; i++){
            //control = 1;
            for(int l=0; l<set2.capacity; l++){
            
                
                    if(set2.container[l].day == container[i].day && set2.container[l].month == container[i].month) {  //If there is the same element in the second set, ignore it. If not, add it to the array.
                        control = 0;
                        dummy[counter] = container[i];    
                   
                    counter++;
                        
                    }
                    
                
             }
            
        }

        DayofYearSet U = new DayofYearSet(dummy,counter);
        return U;   //Return the new constructed object.


    }

    /**
     * @param DayofYearSet obj 
     * @return DayofYearSet
     * Finds the set complement */
     public DayofYearSet complement(DayofYearSet obj){  //Makes a list and removes the same object of same year, returns the new constructed object

        ArrayList<DayofYearSet.DayofYear> mylist = new ArrayList<DayofYearSet.DayofYear>();
        int i,j;
        int l;
        int cnt = 0;
        for(i=1;i<13;i++){

                for(j=1;j<31;j++){
                    DayofYearSet.DayofYear listelem = new DayofYearSet.DayofYear(j,i);
                    mylist.add(listelem);
                    
                    
                }
        }



        DayofYearSet C  = new DayofYearSet(mylist);
        for(i=0;i<C.capacity;i++){

                for(j=0;j<obj.capacity;j++){
                    
                    if(C.container[i].day == obj.container[j].day && C.container[i].month == obj.container[j].month){
                        C.remove(i);
                        break;
                    }
                    
                    
                }
        }

        return C;

    }


    /**
     * @return count
     * Static method for counting the total objects of DayofYear
     */
    public static int total_count(){
        return count;
    }

    public static class DayofYear{


        private int day;
        private int month;
        
        /**
         * Constructor for DayofYear */
        public DayofYear(int d, int m){
            if(d>31 || d<1 || m<1 || m>12){
                System.out.println("Invalid day or month input.");  //Checking the user input validity
                day = 1;
                month = 1;
                
                count++;
            }
            else{
                day = d;
                month = m;
                
                count++;
            }
            
        }

        public int getday(){ //Returns the day
            return day;
        }
        public int getmonth(){  //Returns the month
            return month;
        }
        public void setmonth(int m){    //Sets the month
            month = m;
        }
        public void setday(int d){  //Sets the day
            day = d;
        }
       

    }


}
