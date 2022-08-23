/*ILAYDA ARAR CSE241 HW4 1901042638*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "dayOfYear.cpp"	//Including the cpp file implementation with header.
using namespace std;
using namespace nsday;		//Using our own namespace



int main(){

    string filename = "sets.txt";	//Filename for writing to text file (De Morgan rule is going to be written in this file)
    int sizeofvec;
    int stat_count;
    
    DayofYearSet obj(11,2,13,3);	//Trying constructor for 2 elements
    obj.getCount(obj);			//Counting the objects of DayofYear
    
    DayofYearSet obj2;			//Trying constructor for no elements
    obj2.getCount(obj2);
   

   
    cout << "obj's size is: " << obj.size() << endl;		//Size function testing
    cout << "obj2's size is: " << obj2.size() << endl;

    vector<int> vec = {1,1,6,4,2,5,9,3};		//Creating some vectors for using in objects
    vector<int> vec2 = {8,9,5,4,2,5};
    vector<int> vec3 = {4,5,2,8,11,9,2,5,6,7};
    vector<int> vec4 = {3,4,12,8,11,5,7,3};
    sizeofvec = vec.size();
    int sizeofvec2 = vec2.size();
    int sizeofvec3 = vec3.size();
    int sizeofvec4 = vec4.size();	//Getting the size of the vectors

    DayofYearSet obj3(vec, sizeofvec);	//Trying the vector taking constructor
    DayofYearSet obj4(vec2, sizeofvec2);
    DayofYearSet obj5(vec3, sizeofvec3);
    DayofYearSet obj6(vec4, sizeofvec4);
    obj3.getCount(obj3);
    obj4.getCount(obj4);
    obj5.getCount(obj5);
    stat_count = obj6.getCount(obj6);
    
    cout << "The number of DayofYear objects is: " << stat_count << endl;	//Testing the static counting function
    obj3.add(3,4);
    cout << "Add function used on obj3: " << obj3 << endl;
    obj4.add(10,3);
    cout << "Add function used on obj4: " << obj4 << endl;	//Testing the add function

   obj3.remove();
    cout << "Remove function used on obj3: " << obj3 << endl;	//Testing the remove function

    obj4.remove();
    cout << "Remove function used on obj4: " << obj4 << endl;
    
    cout << "The third day of obj4: " << obj4[2].day << endl;		//Testing the index operator
    cout << "The first month of obj4: " << obj4[0].month << endl;
    
    
    
    cout << "Operator + used on obj 5 and 6: " << (obj5 + obj6);
    cout << "Operator + used on obj 5 and 4: " << (obj5 + obj4) << endl;	//Testing + ^ and - operators

    cout << "Operator - used on obj 3 and 4: " << (obj3 - obj4) << endl;
    cout << "Operator - used on obj 5 and 4: " << (obj5 - obj4) << endl;

    cout << "Operator ^ used on obj 3 and 4: " << (obj3 ^ obj4) << endl;
    cout << "Operator ^ used on obj 5 and 4: " << (obj5 ^ obj4) << endl;
    

    if(obj3 == obj4)
    { 
        cout << "These sets are same\n";
    }
    else if(obj3 != obj4) cout << "These sets are not same\n";

    if(obj5 == obj6)
    { 
        cout << "These sets are same\n";
    }
    else if(obj5 != obj6) cout << "These sets are not same\n";	//Testing the != and == operators


   ofstream myfile (filename);
    myfile << "De morgan rule for obj3 and obj4: " << endl << ((!obj3) ^ (!obj4));	//Writing the complement sets to the text file.
    myfile << "De morgan rule for obj5 and obj4: " << endl << !((obj5) + (obj4));
    myfile << "De morgan rule for obj3 and obj5: " << endl << ((!obj3) ^ (!obj5));
    myfile << "De morgan rule for obj5 and obj6: " << endl << !((obj5) + (obj6));
    myfile << "De morgan rule for obj4 and obj6: " << endl << ((!obj4) ^ (!obj6));
    

   myfile.close();

    return 0;
}
