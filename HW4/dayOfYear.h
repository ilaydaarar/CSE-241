/*ILAYDA ARAR CSE241 HW4 1901042638*/
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


/*The namespace and class interface in header file*/

using namespace std;

namespace nsday
{
    class DayofYearSet
    {
        public:

            class DayofYear
            {
                public:
                    int day;
                    int month;

            };
            
            int size();
            void add(int dayval, int monthval);
            void remove();
            
            bool operator==(DayofYearSet myset1);
            bool operator!=(DayofYearSet myset1);
            static int getCount(DayofYearSet& obj);
            DayofYearSet::DayofYear& operator[](int index);
            friend DayofYearSet operator +(DayofYearSet& set1, DayofYearSet& set2);
            friend DayofYearSet operator -(DayofYearSet& set1, DayofYearSet& set2);
            friend DayofYearSet operator ^(DayofYearSet set1, DayofYearSet set2);
            friend DayofYearSet operator !(DayofYearSet set1);
            friend ostream& operator <<(ostream& outputStream, DayofYearSet myset);

        DayofYearSet(int day1, int month1, int day2, int month2);
        DayofYearSet();
        DayofYearSet(vector<int> vec, int size);
        

        private:
            DayofYear* X;
            int length;
            
       
            


    };
    ostream& operator <<(ostream& outputStream, DayofYearSet myset);
    DayofYearSet operator +(DayofYearSet& set1, DayofYearSet& set2);
    DayofYearSet operator ^(DayofYearSet set1, DayofYearSet set2);
    DayofYearSet operator -(DayofYearSet& set1, DayofYearSet& set2);
    DayofYearSet operator !(DayofYearSet set1);

}

#endif //DAYOFYEAR_H
