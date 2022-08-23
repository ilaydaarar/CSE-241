/*ILAYDA ARAR CSE241 HW4 1901042638*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "dayOfYear.h"

namespace nsday
{
    DayofYearSet::DayofYearSet(int day1, int month1, int day2, int month2){	//The constructor for only 2 elemented set.
            X = new DayofYear[2]; 
            DayofYearSet::DayofYear date;
            if(day1 < 1 || day1 > 30) day1 = 1;
            if(month1 < 1 || month1 > 12) month1 = 1;
            if(day2 < 1 || day2 > 30) day1 = 1;
            if(month2 < 1 || month2 > 12) month1 = 1;	//Correcting the data if the user put false input
            date.day = day1;
            date.month = month1;
            X[0] = date;
            date.day = day2;
            date.month = month2;
            X[1] = date;
            
            length = 2;	//Assigning values to private members.
        }
    DayofYearSet::DayofYearSet(){	//The constructor for no user input. This constructor fills a 10 element array with 1.1 data
            X = new DayofYear[10]; 
            DayofYearSet::DayofYear date;
            date.day = 1;
            date.month = 1;
            for(int i = 0; i<10; i++){
                X[i] = date;
            }
            length = 10;
    }
    DayofYearSet::DayofYearSet(vector<int> vec, int len){	//The constructor for vector data
            X = new DayofYear[len/2]; 
            int j;
            int k = 0;
            int l = 0;
            DayofYearSet::DayofYear date;
           
            for(int i = 0; i<len/2 ; i++){
                if(vec[l] < 1 || vec[l] > 30) vec[l] = 1;	//Correcting data if necessary
                if(vec[l+1] < 1 || vec[l+1] > 12) vec[l+1] = 1;
                date.day = vec[l];  
                date.month = vec[l+1];	//Filling the pointer array with vector values.
                l = l+2;
                X[k] = date;
                k++;
            }
            length = len/2;
    }

    
           
    int DayofYearSet::getCount(DayofYearSet& obj){	//Static function for counting the objects of DayofYear
        static int count = 0;
        count = count + obj.length;
        return count;	//Adding each time called and returns the count

    }
    
    
    int DayofYearSet::size(){	//Returns the size of the set
       
        return length;
    }

    void DayofYearSet::add(int dayval, int monthval) { 	//Add function for adding an element in the last place of set
        DayofYear *pnew; 
        int control = 1;
         
         for(int i=0; i<length; i++){
            
            
                if(X[i].day == dayval && X[i].month == monthval) {	//Checking if there is a duplicate of the value that was wanted to be added
                   control = 0;
                }
                
            
        }
        if(control == 1){
        pnew = new DayofYear[length]; 
        for (int i = 0; i < length; i++){	//Copying the array into a new array
            pnew[i] = X[i]; 
        }
        
        
        for (int j = length; j < length+1; j++){	//Adding a empty space
            pnew[j] = {0,0}; 
        }
        
         
        
        X = pnew; 	//Assigning our own array to the new one created
        
        X[length].day = dayval; 
        X[length].month = monthval;	//Adding the value
        length = length + 1;	//The length of the array is +1 now
        }
        else if(control == 0) cout << "No duplicates allowed in set" << endl;	//Error message for a duplicate element
    }

    void DayofYearSet::remove() { 	//Removes the last element from set
        DayofYear *pnew; 
        
       
        pnew = new DayofYear[length-1]; 
        for (int i = 0; i < length-1; i++){	//Copying all of the array to a new one except of the last element
            pnew[i] = X[i]; 
        }
        
        
        X = pnew; //Assigning it back.
        
        length = length - 1;	//Decrementing the length member
    }  

    bool DayofYearSet::operator==(DayofYearSet myset){	//Overloaded == operator for checking 2 sets
        
        bool control = false;
        int match = 0;
        
        auto i = 0;
        decltype(i) j;

        if(myset.length == length){
        for(i=0; i<length; i++){
            
            for(j=0; j<length; j++){
                if(X[i].day == myset[j].day && X[i].month == myset[j].month) {	//If there is a match, decrement it
                    match++;
                }
                
            }
        }
        }
        if(match == length) control = true;	//If the match count and the length of the array is same, they are the same.
        else control = false;
        return control;
    }

    bool DayofYearSet::operator!=(DayofYearSet myset){	//Overloaded != operator for checking 2 sets
        int i,j;
        bool control = false;
        int match = 0;
        
        if(myset.length == length){
        for(i=0; i<length; i++){
            
            for(j=0; j<length; j++){
                if(X[i].day == myset[j].day && X[i].month == myset[j].month) {	//If there is a match, decrement it
                    match++;
                }
                
            }
        }
        }
        
        if(match != length) control = true;	//If the match count and the length of the array is not same, they are not the same.
        else if(match == length) control = false;
       
        return control;
    }

    DayofYearSet::DayofYear& DayofYearSet::operator[](int index){	// Overloaded index operator for reaching elements.
        int i = 0;
        for(i = 0; i<length; i++){
            if(i == index){
                index = i;	//When the index number is reached, return the pointer to the set
            }
        }
        return *(X+index);
    }

    DayofYearSet operator +(DayofYearSet& set1, DayofYearSet& set2){	//Overloaded + operator for unionizing the sets
        
        int control = 1;
        vector<int> vec;

        for(int i = 0; i<set1.length; i++){	//Taking all of the set1 and pushing it to a vector.

            vec.push_back(set1[i].day);
            vec.push_back(set1[i].month);
        }
        for(int i = 0; i<set2.length; i++){
            control = 1;
            for(int l=0; l<set1.length; l++){
            
                
                    if(set2[i].day == set1[l].day && set2[i].month == set1[l].month) {	//If there is the same element in the second set, ignore it. If not, add it to the vector.
                        control = 0;
                        
                    }
                    
                
             }
            if(control == 1){
            vec.push_back(set2[i].day);
            vec.push_back(set2[i].month);
            }
        }
        return DayofYearSet(vec, vec.size());	//Return the new constructed union object.

    }

    DayofYearSet operator ^(DayofYearSet set1, DayofYearSet set2){	//Overloaded ^ operator for finding the same elements in sets.
        
        int control = 1;
        vector<int> vec;

        
        for(int i = 0; i<set1.length; i++){
           
            for(int l=0; l<set2.length; l++){
            
                
                    if(set2[l].day == set1[i].day && set2[l].month == set1[i].month) {	//If there is a same element, add it to the vector
                        
                        vec.push_back(set1[i].day);
                        vec.push_back(set1[i].month);

                    }
                    
                
             }
           
        }
        return DayofYearSet(vec, vec.size());	//Return the new constructed intersection object.

    }

    DayofYearSet operator -(DayofYearSet& set1, DayofYearSet& set2){	//The overloaded - operator for finding the difference of sets
        
        int control = 1;
        vector<int> vec;

        
        for(int i = 0; i<set1.length; i++){
            control = 1;
            for(int l=0; l<set2.length; l++){
            
                    
                    if(set2[l].day == set1[i].day && set2[l].month == set1[i].month) {	//If there is the same element in the second set, ignore it. If not, add it to the vector.
                        control = 0;
                       

                    }
                    
                
             }
             if(control == 1){
                vec.push_back(set1[i].day);
                vec.push_back(set1[i].month);
             }
           
        }

        return DayofYearSet(vec, vec.size());	//Return the new constructed difference object.

    }

    DayofYearSet operator !(DayofYearSet set1){	//Overloaded ! operator for finding the complements of sets
        
       
        vector<int> vec;
        int i,j;

        for(i=1;i<13;i++){

                for(j=1;j<31;j++){
                    vec.push_back(j);	//Creating a vector with all of the days in a year
                    vec.push_back(i);
                }
        }
        DayofYearSet complete(vec, vec.size());	//Constructing an object with the vector
       
        
        return (complete - set1);	//Returning the difference of the wanted set.

    }

    ostream& operator <<(ostream& outputStream, DayofYearSet myset){	//Overloaded << stream operator for printing the details of the sets

        outputStream << "{ " ;

        for(int i = 0; i<myset.size(); i++){

             outputStream << "(" ;
             outputStream << myset[i].day << ".";
             outputStream << myset[i].month << ")" << ", ";	//Outputting the well written set.

        }
        outputStream << " }" ;
        outputStream << endl;
        return outputStream;
    }
    

}
